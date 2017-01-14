#include "EdgeWeightedDiGraph.h"

EdgeWeightedDiGraph::EdgeWeightedDiGraph(int V)
{
    this->V = V;
    this->E = 0;
    adj = std::vector<std::vector<DirectedEdge>>(V,std::vector<DirectedEdge>());
}

EdgeWeightedDiGraph::EdgeWeightedDiGraph(std::istream &is)
{
    is>>this->V;
    is>>this->E;
    node nodes[this->V];
    this->adj = std::vector<std::vector<DirectedEdge>>(this->V,std::vector<DirectedEdge>());

    for (int i = 0; i < this->V; ++i) {
        int ID = 0,x = 0,y = 0;
        is>>ID>>x>>y;
        nodes[ID] = node(ID,(double)x,(double)y);
    }

    for(int i = 0;i<this->E;++i)
    {
        int v = 0,w = 0;
        is>>v>>w;
        DirectedEdge e1(nodes[v],nodes[w]);
        DirectedEdge e2(nodes[w],nodes[v]);
        this->adj[e1.from()].push_back(e1);
        this->adj[e2.from()].push_back(e2);
    }
}

std::vector<DirectedEdge> EdgeWeightedDiGraph::getedges()
{
    std::vector<DirectedEdge> v;
    for (size_t i = 0; i < this->V; ++i) {
        for(auto e : this->adj[i])
            v.push_back(e);
    }
    return v;
}
