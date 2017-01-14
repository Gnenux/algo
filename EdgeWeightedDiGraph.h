#ifndef __EDGEWEIGHTEDDIGRAPH_H
#define __EDGEWEIGHTEDDIGRAPH_H

#include <iostream>
#include <vector>
#include "DirectedEdge.h"

class EdgeWeightedDiGraph
{
public:
    EdgeWeightedDiGraph(int V);
    EdgeWeightedDiGraph(std::istream &is);

    int getV(){return this->V;}
    int getE(){return this->E;}
    void addEdge(DirectedEdge e){this->adj[e.from()].push_back(e);E++;}
    std::vector<DirectedEdge> getadj(int v){return this->adj[v];}
    std::vector<DirectedEdge> getedges();

private:
    int V;      //顶点数
    int E;      //边数
    std::vector<std::vector<DirectedEdge>> adj;     //边集
};

#endif
