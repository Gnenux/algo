#ifndef __PERCOLATION_H
#define __PERCOLATION_H

#include "WQUUF.h"

class Percolation
{
public:
    Percolation(int N);
    void open(int x,int y);
    bool isOpen(int x,int y);
    bool isFull(int x,int y);
    bool percolates();
    ~Percolation()
    {
        delete UFT;
        delete UFB;
        delete [] matrix;
    }

private:
    void validate(int x,int y);
    bool *matrix;       //标记网格的打开与关闭情况
    int row,col;
    WQUUF *UFB;         //首尾虚拟节点的维护，用在percolates的判断中，WQUUF是加权quick-union算法
    WQUUF *UFT;         //负责维护首虚拟节点，避免backwash的问题
    bool haspercolate;
};

#endif
