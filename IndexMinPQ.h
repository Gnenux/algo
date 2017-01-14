#ifndef __INDEXMINPQ_H
#define __INDEXMINPQ_H

#include <cstddef>

template<typename T>
class IndexMinPQ
{
public:
    IndexMinPQ(int maxN);
    bool isEmpty();
    bool contains(int i){return this->qp[i] !=-1;}
    int size(){return this->n;}
    void insert(int i,T key);
    int minIndex(){return this->pq[1];}
    T minKey(){return this->keys[this->pq[1]];}
    int delMin();
    void change(int i,T key){this->keys[i] = key;this->swim(this->qp[i]);this->sink(this->qp[i]);}
    ~IndexMinPQ(){delete [] this->keys;delete [] this->pq;delete [] this->qp;}
private:
    bool greater(int i,int j);
    void exch(int i,int j);
    void swim(int k);
    void sink(int k);
    int maxN;
    int n;
    int *pq;
    int *qp;
    T *keys;
};

template <typename T>
IndexMinPQ<T>::IndexMinPQ(int maxN)
{
    this->maxN = maxN;
    n = 0;
    keys = new T[maxN+1];
    pq = new int[maxN+1];
    qp = new int[maxN+1];
    for (int i = 0; i < maxN; i++) {
        qp[i] = -1;
    }
}

template <typename T>
bool IndexMinPQ<T>::isEmpty()
{
    return this->n==0;
}

template <typename T>
void IndexMinPQ<T>::insert(int i,T key)
{
    this->n++;
    this->qp[i] = n;
    this->pq[n] = i;
    this->keys[i] = key;
    this->swim(n);
}

template <typename T>
void IndexMinPQ<T>::swim(int k)
{
    while (k>1 && this->greater(k/2,k)) {
        this->exch(k,k/2);
        k = k/2;
    }
}

template <typename T>
void IndexMinPQ<T>::sink(int k)
{
    while (2*k<=this->n) {
        int j = 2*k;
        if(j<this->n && this->greater(j,j+1))
            j++;
        if(!this->greater(k,j))
            break;
        this->exch(k,j);
        k = j;
    }
}

template <typename T>
bool IndexMinPQ<T>::greater(int i, int j)
{
    return keys[pq[i]] > keys[pq[j]];
}

template <typename T>
void IndexMinPQ<T>::exch(int i,int j)
{
    int swap = this->pq[i];
    this->pq[i] = this->pq[j];
    this->pq[j] = swap;
    this->qp[this->pq[i]] = i;
    this->qp[this->pq[j]] = j;
}

template <typename T>
int IndexMinPQ<T>::delMin()
{
    int min = this->pq[1];
    this->exch(1,n--);
    sink(1);
    if(min==this->pq[n+1])
    {
        this->qp[min] = -1;
        //this->keys[min] = NULL;
        this->pq[n+1] = -1;
        return min;
    }
}



#endif
