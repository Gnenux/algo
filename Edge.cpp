#include "Edge.h"

node Edge::other(node vertex)
{
    if(vertex.getid()==this->v.getid())
    {
        return w;
    }
    else if(vertex.getid()==this->w.getid())
    {
        return v;
    }
}

int Edge::compareTo(Edge that)
{
    if(this->weight<that.weight)
        return -1;
    else if(this->weight > that.weight)
        return +1;
    else
        return 0;
}

std::string Edge::toString()
{
    
    return
}
