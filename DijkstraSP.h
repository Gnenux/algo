#ifndef __SP_H
#define __SP_H
#include "EdgeWeightedDiGraph.h"
#include "IndexMinPQ.h"

class DijkstraSP
{
public:
    DijkstraSP(EdgeWeightedDiGraph &G,int s);
    double getdistTo(int v){return this->distTo[v];}
    std::vector<DirectedEdge> getpathTo(int v);
    bool hasPathTo(int v);
    std::vector<DirectedEdge> pathTo(int v);
    ~DijkstraSP(){delete [] edgeTo;delete [] distTo;}
private:
    void relax(DirectedEdge e);         //边的松弛
    void relax(int v);          //点的松弛
    EdgeWeightedDiGraph &G;     //图
    int s;                  //源点
    DirectedEdge *edgeTo;       //从源点到某一点的最短路径，没有则空
    double *distTo;                 //从源点到某一点的距离，没有则无穷大
    IndexMinPQ<double> *pq;         //关联索引优先队列

};
#endif
