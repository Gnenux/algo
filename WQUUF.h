#ifndef __WQUUF_H
#define __WQUUF_H

#include <iostream>

class WQUUF {
public:
    WQUUF(int n);
    int Count() {return this->count_num;}
    int Find(int p);
    bool Connected(int p, int q) {return Find(p) == Find(q);}
    void Union(int p, int q);

    ~WQUUF()
    {
        delete [] parent;
        delete [] size;
    }
private:
    void validate(int p);
    int *parent;
    int *size;
    int count_num =0;
    int length =0;
};

#endif
