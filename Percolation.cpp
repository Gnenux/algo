#include "Percolation.h"
#include <iostream>
Percolation::Percolation(int N)
{
    if(N<1)
    {
        std::cout<<"the number of N is too small!"<<std::endl;
        exit(-1);
    }
    UFB = new WQUUF(N*N+2);
    UFT = new WQUUF(N*N+1);
    haspercolate = false;
    row = N;
    col = N;
    matrix = new bool[N*N+1];
    for (size_t i = 0; i < N*N+1; i++) {
        matrix[i] = false;
    }
}

void Percolation::validate(int x,int y)
{
    if((x<1||x>row)||(y<1||y>col))
    {
        std::cout <<"out of bounds"<< '\n';
        exit(-1);
    }
}

void Percolation::open(int x,int y)
{
    validate(x,y);
    int curx = (x-1)*col+y; //定位（x，y）在matrix中的位置
    matrix[curx] = true;
    if(x==1)        //特殊情况
    {
        UFB->Union(curx,0);
        UFT->Union(curx,0);
    }

    if(x==row)      //特殊情况
    {
        UFB->Union(curx,row*col+1);//UFT不能也进行连通，不然无法避免backwash
    }

    int dx[] = {1,-1,0,0};//用于四个方向的连接
    int dy[] = {0,0,1,-1};//用于四个方向的连接

    for (size_t i = 0; i < 4; i++) {
        int posx = x+dx[i];
        int posy = y+dy[i];
        if(posx<=row && posx>=1&&posy<=row&&posy>=1&&isOpen(posx,posy))
        {
            UFB->Union(curx,(posx-1)*col+posy);
            UFT->Union(curx,(posx-1)*col+posy);
        }
    }
}

bool Percolation::isOpen(int x, int y)
{
    return matrix[(x-1)*col + y];
}
bool Percolation::isFull(int x,int y)
{
    validate(x,y);
    int curx = (x-1)*col+y;
    if(UFT->Find(curx)==UFB->Find(0))
    {
        return true;
    }
    return false;
}

bool Percolation::percolates()
{
    if(haspercolate)
    {
        return true;
    }

    if(UFB->Find(0) == UFB->Find(row*col+1))
    {
        haspercolate = true;
        return true;
    }
    return false;
}
