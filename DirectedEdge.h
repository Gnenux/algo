#ifndef __DIRECTEDEDGE_H
#define __DIRECTEDEDGE_H

#include "node.h"
#include <string>

class DirectedEdge
{
public:
    DirectedEdge(){this->v = node(-1,0.0,0.0);this->w = node(-1,0.0,0.0);this->weight = -1.0;}
    DirectedEdge(node v,node w):v(v),w(w){this->weight = getdistance(v,w);}
    DirectedEdge(int v1,int v2,double weight):weight(weight){this->v = node(v1,0,0);this->w = node(v2,0,0);}
    double getweight(){return this->weight;}

    int from(){return this->v.getid();}

    int to(){return this->w.getid();}

    std::string toString();

private:
    node v;     //点一
    node w;     //点二
    double weight;  //长度
};

#endif
