#include "arbiter.ih"

Arbiter::Arbiter(Alternatives const &alternatives)
:
    d_index(alternatives.size()),
    d_alternatives(alternatives)
{}


