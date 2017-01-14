#ifndef __PERCOLATIONSTATS_H
#define __PERCOLATIONSTATS_H

#include "Percolation.h"

class PercolationStats
{
public:
    PercolationStats(int N,int T);
    double mean();
    double stddev();
    double confidenceLo();
    double confidenceHi();
    ~PercolationStats()
    {
        delete [] x;
    }
private:
    double *x;
    int expTimes;
};

#endif
