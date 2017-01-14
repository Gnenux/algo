#ifndef __QUICKSORT_H
#define __QUICKSORT_H

#include <iostream>
#include <vector>
#include <random>

template <typename T>
class Quicksort
{
public:
    Quicksort(std::vector<T> v):a(v){}
    void randomsort();
    void randomsort(int lo,int hi);
    void sort();
    void sort(int lo,int hi);
private:
    int partition(int lo,int hi);
    int randompartition(int lo,int hi);
    void printVec();
    std::vector<T> a;

};

template <typename T>
void Quicksort<T>::randomsort()
{
    this->randomsort(0,this->a.size()-1);
}

template <typename T>
void Quicksort<T>::randomsort(int lo, int hi)
{
    if(hi<=lo) return;
    int j = this->randompartition(lo,hi);
    this->printVec();
    this->randomsort(lo,j-1);
    this->randomsort(j+1,hi);
}

template <typename T>
void Quicksort<T>::sort()
{
    this->sort(0,this->a.size()-1);
}

template <typename T>
void Quicksort<T>::sort(int lo,int hi)
{
    if(hi<=lo) return;
    int j = this->partition(lo,hi);
    this->printVec();
    sort(lo,j-1);
    sort(j+1,hi);
}

template <typename T>
int Quicksort<T>::partition(int lo,int hi)
{
    int i = lo,j = hi+1;
    T v = this->a[lo];
    while (true) {
        while (this->a[++i]<v) {
            if(i==hi) break;
        }
        while (v<this->a[--j]) {
            if(j==lo) break;
        }
        if(i>=j) break;
        T tmp = this->a[i];
        a[i] = this->a[j];
        a[j] = tmp;
    }
    T tmp = this->a[lo];
    a[lo] = this->a[j];
    a[j] = tmp;
    return j;
}

template <typename T>
int Quicksort<T>::randompartition(int lo, int hi)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(lo,hi);
    int j = dist(rd);
    T tmp = this->a[hi];
    this->a[hi] = this->a[j];
    this->a[j] = tmp;
    return this->partition(lo,hi);
}

template <class T>
void Quicksort<T>::printVec()
{
    int num = this->a.size();
    for(int i =0;i<num;i++)
    {
        std::cout<<this->a[i]<<" ";
    }
    std::cout<<std::endl;
}

#endif
