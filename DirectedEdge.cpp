#include "DirectedEdge.h"

std::string DirectedEdge::toString()
{
    char tmp[64];
    sprintf(tmp,"%d->%d %.2f",v.getid(),w.getid(),this->weight);
    return std::string(tmp);
}
