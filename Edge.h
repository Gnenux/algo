#ifndef __EDGE_H
#define __EDGE_H
#include "node.h"
#include <string>

class Edge
{
public:
    Edge(node v,node w):v(v),w(w){this->weight = getdistance(v,w);}
    double weight(){return this->weight;}
    node either(){return v;}
    node other(node vertex);
    int compareTo(Edge that);
    std::string toString();
private:
    node v;
    node w;
    double weight;
};

#endif
