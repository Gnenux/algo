#include "WQUUF.h"

WQUUF::WQUUF(int n) {
        this->count_num = n;
        this->length = n;
        this->parent = new int[n]();
        this->size = new int[n]();
        for (int i = 0; i < n; i++) {
            this->parent[i] = i;
            this->size[i] = 1;
        }

}

int WQUUF::Find(int p) {
        validate(p);
        while (p != parent[p])
            p = parent[p];
        return p;
}

void WQUUF::Union(int p, int q) {
        int rootP = Find(p);
        int rootQ = Find(q);
        if (rootP == rootQ) return;

        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        this->count_num--;
}

void WQUUF::validate(int p) {
    int n = length;
    if (p < 0 || p >= n) {
        std::cout<<"index "<<p<<" is not between 0 and "<<(n-1)<<std::endl;
    }
}
