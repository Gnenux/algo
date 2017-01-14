#include "PercolationStats.h"
#include <random>
#include <cmath>

PercolationStats::PercolationStats(int N,int T)
{
        x = new double[T+1]();
        for (size_t i = 0; i < T+1; i++) {
            x[i] = 0.0;
        }
        expTimes = T;
        std::random_device rd;
        std::uniform_int_distribution<int> dist(0, N-1);

        for (size_t i = 1; i <= T; i++) {
            Percolation perc(N);

            bool *isEmptySiteLine = new bool[N+1];
            for (size_t j = 0; j < N+1; j++) {
                isEmptySiteLine[j] = false;
            }

            int numOfLine = 0;
            while (true) {
                int posx,posy;
                do{
                    posx = dist(rd)+1;          //随机x
                    posy = dist(rd)+1;          //随机y
                }while(perc.isOpen(posx,posy));     //上面随机取值应该有一个优化方案：生成一个随机坐标的栈，
                                                    //但是我做了一个，性能太差了
                perc.open(posx,posy);
                x[i] = x[i]+1;
                if(!isEmptySiteLine[posx])
                {
                    isEmptySiteLine[posx] = true;
                    numOfLine++;
                }

                if(numOfLine ==N)
                {
                    if(perc.percolates())
                    {
                        break;
                    }
                }
            }
            x[i] = x[i]/(double) (N*N);
            delete [] isEmptySiteLine;
        }

}

double PercolationStats::mean()
{
    double mu = 0.0;
    for (size_t i = 1; i < expTimes; i++) {
        mu += x[i];
    }
    return mu/(double)expTimes;
}

double PercolationStats::stddev()
{
    double tmp = 0.0;
    double mu = mean();
    for (int i = 1; i <= expTimes; ++i) {
        tmp += (x[i]-mu)*(x[i]-mu);
    }
    return std::sqrt(tmp / (double) (expTimes-1));
}

double PercolationStats::confidenceLo()
{
    double mu = mean();
    double dev = stddev();
    return mu -1.96*dev/std::sqrt(expTimes);
}

double PercolationStats::confidenceHi()
{
    double mu = this->mean();
    double dev = this->stddev();
    return mu+1.96*dev/std::sqrt(expTimes);
}
