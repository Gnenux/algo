#include "WQUUF.h"
#include "Percolation.h"
#include "PercolationStats.h"
#include <iostream>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int N = 200;
    int T = 100;
    PercolationStats percStats(N, T);
    printf("mean = %f\n", percStats.mean());
    printf("stddev = %f\n", percStats.stddev());
    printf("95%% confidence interval = %f, %f\n",
                  percStats.confidenceLo(), percStats.confidenceHi());
    return 0;
}
