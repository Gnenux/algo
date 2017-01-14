#ifndef __MERGE_H
#define __MERGE_H

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class Merge
{
public:
    Merge(std::vector<T> v):data(v){std::vector<T> tmp(data.size());aux = tmp;}
    void sort();
    void sort(int lo,int hi);
    void sortBU();
private:
    void merge(int lo,int mid,int hi);
    void printVec();
    std::vector<T> data;
    std::vector<T> aux;
};

template <typename T>
void Merge<T>::merge(int lo, int mid, int hi)
{
    int i = lo,j = mid+1;
    for (size_t k = lo; k <=hi ; k++) {
        this->aux[k] = this->data[k];
    }

    for (size_t k = lo; k <= hi; k++) {
        if(i>mid)               this->data[k] = this->aux[j++];
        else if(j>hi)           this->data[k] = this->aux[i++];
        else if(aux[j]<aux[i])  this->data[k] = this->aux[j++];
        else                    this->data[k] = this->aux[i++];
    }

}

template <typename T>
void Merge<T>::sort()
{
    this->sort(0,this->data.size()-1);
}

template <typename T>
void Merge<T>::sort(int lo, int hi)
{
    if(hi<=lo) return;
    int mid = lo + (hi-lo)/2;
    this->sort(lo,mid);
    this->sort(mid+1,hi);
    this->merge(lo,mid,hi);
    this->printVec();
}

template <typename T>
void Merge<T>::sortBU()
{
    for (size_t sz = 1; sz < this->data.size(); sz = sz+sz) {
        for (size_t lo = 0; lo < this->data.size()-sz; lo+=sz+sz) {
            this->merge(lo,lo+sz-1,std::min(lo+sz+sz-1,this->data.size()-1));
            this->printVec();
        }
    }
}

template <class T>
void Merge<T>::printVec()
{
    int num = this->data.size();
    for(int i =0;i<num;i++)
    {
        std::cout<<this->data[i]<<" ";
    }
    std::cout<<std::endl;
}

#endif
