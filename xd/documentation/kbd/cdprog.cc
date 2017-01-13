// Enter has keycode 28, and is generated from \n

#include <linux/input.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <unordered_map>
#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono;

unordered_map<int, int> chCodes 
{
    {'1',   2     },  
    {'2',   3     },
    {'3',   4     },
    {'4',   5     },
    {'5',   6     },
    {'6',   7     },
    {'7',   8     },
    {'8',   9     },
    {'9',  10     },
    {'0',  11     },
    {'-',  12     },
    {'=',  13     },
    {'q',  16     },
    {'w',  17     },
    {'e',  18     },
    {'r',  19     },
    {'t',  20     },
    {'y',  21     },
    {'u',  22     },
    {'i',  23     },
    {'o',  24     },
    {'p',  25     },
    {'[',  26     },
    {']',  27     },

    {'\n', 28     },  

    {'a',  30     },
    {'s',  31     },
    {'d',  32     },
    {'f',  33     },
    {'g',  34     },
    {'h',  35     },
    {'j',  36     },
    {'k',  37     },
    {'l',  38     },
    {';',  39     },
    {'\'', 40     },   
    {'`',  41     },

    // L shift key has code 42

    {'\\', 43     },
    {'z',  44     },
    {'x',  45     },
    {'c',  46     },
    {'v',  47     },
    {'b',  48     },
    {'n',  49     },
    {'m',  50     },
    {',',  51     },
    {'.',  52     },
    {'/',  53     },
    {' ',  57     },
    {'!',  64 + 2 },    // & 64 -> shift. keycode is & 63       
    {'@',  64 + 3 },    
    {'#',  64 + 4 },    
    {'$',  64 + 5 },    
    {'%',  64 + 6 },    
    {'^',  64 + 7 },    
    {'&',  64 + 8 },    
    {'*',  64 + 9 },    
    {'(',  64 + 10},        
    {')',  64 + 11},        
    {'_',  64 + 12},        
    {'+',  64 + 13},        
    {'Q',  64 + 16},        
    {'W',  64 + 17},        
    {'E',  64 + 18},        
    {'R',  64 + 19},        
    {'T',  64 + 20},        
    {'Y',  64 + 21},        
    {'U',  64 + 22},        
    {'I',  64 + 23},        
    {'O',  64 + 24},        
    {'P',  64 + 25},        
    {'{',  64 + 26},        
    {'}',  64 + 27},        
    {'A',  64 + 30},        
    {'S',  64 + 31},        
    {'D',  64 + 32},        
    {'F',  64 + 33},        
    {'G',  64 + 34},        
    {'H',  64 + 35},        
    {'J',  64 + 36},        
    {'K',  64 + 37},        
    {'L',  64 + 38},        
    {':',  64 + 39},        
    {'"',  64 + 40},        
    {'~',  64 + 41},        
    {'|',  64 + 43},        
    {'Z',  64 + 44},        
    {'X',  64 + 45},        
    {'C',  64 + 46},        
    {'V',  64 + 47},        
    {'B',  64 + 48},        
    {'N',  64 + 49},        
    {'M',  64 + 50},        
    {'<',  64 + 51},        
    {'>',  64 + 52},        
    {'?',  64 + 53},
};

enum
{
    KEY_RELEASED =  0,
    KEY_PRESSED =   1,     
    KEY_EVENT =     EV_KEY,         // from linux/input.h
    L_SHIFT =       KEY_LEFTSHIFT   // from linux/input-event-codes.h,
                                    // included by linux/input.h
};
    
struct input_event ev = {0, KEY_EVENT}; // time: not used (0),
                                        // type: KEY_EVENT

int fd;                                 // set to the device's FD

void event(int keyCode, int action)
{
    ev.type = EV_KEY;
    ev.code = keyCode;
    ev.value = action;
    write(fd, &ev, sizeof(struct input_event));
}
    
void event(int keyCode)
{
    event(keyCode, KEY_PRESSED);
    event(keyCode, KEY_RELEASED);
}

bool shift = false;

void insert(int ch)
{
    int keyCode = chCodes[ch];

    if (keyCode & 64 and not shift)
    {
        shift = true;
        event(L_SHIFT, KEY_PRESSED);
        keyCode & 63;                  // remove the shift-indicator
    }
    else if (not (keyCode & 64) and shift)
    {
        shift = false;
        event(L_SHIFT, KEY_RELEASED);
    }

    event(keyCode);
}

void insert(string const &chars)
{
    for (int ch: chars)
        insert(ch);
}
        
void cdTo(string const &path)
{
    insert("chdir ");
    insert(path);
    insert("\n\n");
//    this_thread::sleep_for(milliseconds(10));
}
    
int main()
try
{
    uid_t uid = getuid();
    seteuid(0);
    fd = open("/dev/input/event0", O_WRONLY);
    seteuid(uid);

    if (fd < 0)
        throw runtime_error("can't open /dev/input/event0");

    string str;
    cout << "enter directory to cd to: ";
    getline(cin, str);
    
    cdTo(str);

//    cout << '\n';
}
catch (exception const &exc)
{
    cout << exc.what() << '\n';
}
