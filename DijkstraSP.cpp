#include "DijkstraSP.h"
#include <cfloat>

DijkstraSP::DijkstraSP(EdgeWeightedDiGraph &G,int s):G(G),s(s)
{
    this->edgeTo = new DirectedEdge[G.getV()];
    this->distTo = new double[G.getV()];
    pq = new IndexMinPQ<double>(G.getV());

    for (size_t i = 0; i < G.getV(); i++) {
        distTo[i] = DBL_MAX;
    }
    this->distTo[s] = 0.0;
    pq->insert(s,0.0);
    while (!pq->isEmpty()) {
        relax(pq->delMin());
    }
}

void DijkstraSP::relax(DirectedEdge e)
{
    int v = e.from(),w = e.to();
    if(this->distTo[w]>this->distTo[v]+e.getweight())
    {
        this->distTo[w] = this->distTo[v]+e.getweight();
        this->edgeTo[w] = e;
    }
}

void DijkstraSP::relax(int v)
{
    for(DirectedEdge e : this->G.getadj(v))
    {
        int w = e.to();
        if(this->distTo[w]>this->distTo[v]+e.getweight())
        {
            this->distTo[w] = this->distTo[v]+e.getweight();
            this->edgeTo[w] = e;
            if(pq->contains(w))
                pq->change(w,this->distTo[w]);
            else
                pq->insert(w,distTo[w]);
        }
    }
}

bool DijkstraSP::hasPathTo(int v)
{
    return this->distTo[v]< DBL_MAX;
}

std::vector<DirectedEdge> DijkstraSP::pathTo(int v)
{
    std::vector<DirectedEdge> vec(0);
    if(!this->hasPathTo(v))
        return vec;
    for (DirectedEdge e = this->edgeTo[v]; e.getweight()>=0.0; e = this->edgeTo[e.from()]) {
        vec.push_back(e);
        v = e.from();
        if(v==this->s)
            break;
    }
    return vec;
}
