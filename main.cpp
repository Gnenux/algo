#include "WQUUF.h"
#include "Percolation.h"
#include "PercolationStats.h"
#include "Insertionsort.h"
#include "Merge.h"
#include "Quicksort.h"
#include "DijkstraSP.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <random>
#include <cfloat>
#include <ctime>
#include <iomanip>
#include <chrono>

int main(int argc, char const *argv[]){


    // int N = 400;
    // int T = 100;
    // PercolationStats percStats(N, T);
    // std::cout << "渗透问题" << '\n';
    // std::cout << "N = " <<N<<" T = "<<T<< '\n';
    // printf("mean = %f\n", percStats.mean());
    // printf("stddev = %f\n", percStats.stddev());
    // printf("95%% confidence interval = %f, %f\n",percStats.confidenceLo(), percStats.confidenceHi());

    std::vector<int> vec;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 100);
    for (size_t i = 0; i < 100; i++) {
        vec.push_back(dist(rd));
    }
    std::cout << "\n" << '\n';

    std::cout << "插入排序" << '\n';
    auto starttime = std::chrono::high_resolution_clock::now();
    Insertionsort<int> IST(vec);
    IST.sort();
    auto endtime = std::chrono::high_resolution_clock::now();
    std::cout << std::fixed << std::setprecision(3) << "花费时间: "
              << std::chrono::duration<double, std::milli>(endtime-starttime).count()
              << " ms\n";
    std::cout << "\n" << '\n';

    std::cout << "归并排序" << '\n';
    starttime = std::chrono::high_resolution_clock::now();
    Merge<int> MST(vec);
    MST.sort();
    endtime = std::chrono::high_resolution_clock::now();
    std::cout << std::fixed << std::setprecision(3) << "花费时间: "
              << std::chrono::duration<double, std::milli>(endtime-starttime).count()
              << " ms\n";
    std::cout << "\n" << '\n';

    std::cout << "随机化快速排序" << '\n';
    starttime = std::chrono::high_resolution_clock::now();
    Quicksort<int> RQST(vec);
    RQST.randomsort();
    endtime = std::chrono::high_resolution_clock::now();
    std::cout << std::fixed << std::setprecision(3) << "花费时间: "
              << std::chrono::duration<double, std::milli>(endtime-starttime).count()
              << " ms\n";
    std::cout << "\n" << '\n';

    std::cout << "快速排序" << '\n';
    starttime = std::chrono::high_resolution_clock::now();
    Quicksort<int> QST(vec);
    QST.sort();
    endtime = std::chrono::high_resolution_clock::now();
    std::cout << std::fixed << std::setprecision(3) << "花费时间: "
              << std::chrono::duration<double, std::milli>(endtime-starttime).count()
              << " ms\n";
    std::cout << "\n" << '\n';

    EdgeWeightedDiGraph G(std::cin);
    int s = 125;
    int t = 128;
    DijkstraSP sp(G,s);

    if(sp.hasPathTo(t))
    {
        printf("%d to %d (%.2f) ",s,t,sp.getdistTo(t) );
        auto vec = sp.pathTo(t);
        auto l_iter = vec.rend();
        for(auto r_iter = vec.rbegin();r_iter != l_iter;++r_iter)
            printf("%s ",(*r_iter).toString().c_str() );
        printf("\n" );
    }
    else{
        printf("%d to %d         no path\n", s, t);
    }

    return 0;
}
