#include "arbiter.ih"

Arbiter::Arbiter(Alternatives &alternatives)
:
    d_index(alternatives.size()),
    d_alternatives(alternatives)
{}



