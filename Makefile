GCC = g++
CFLAGS = -std=c++11

main:WQUUF.o Percolation.o PercolationStats.o Merge.o Quicksort.o Insertionsort.o node.o DirectedEdge.o IndexMinPQ.o EdgeWeightedDiGraph.o DijkstraSP.o
	${GCC} main.cpp -o main WQUUF.o Percolation.o PercolationStats.o Merge.o Quicksort.o Insertionsort.o node.o DirectedEdge.o IndexMinPQ.o EdgeWeightedDiGraph.o DijkstraSP.o  ${CFLAGS}

PercolationStats.o:PercolationStats.h PercolationStats.cpp Percolation.o
	${GCC} PercolationStats.h PercolationStats.cpp -c ${CFLAGS}

Percolation.o:Percolation.h Percolation.cpp WQUUF.o
	${GCC} Percolation.h Percolation.cpp -c ${CFLAGS}

Insertionsort.o:Insertionsort.h Insertionsort.cpp
	${GCC} Insertionsort.h Insertionsort.cpp -c ${CFLAGS}

Merge.o:Merge.h Merge.cpp
	${GCC} Merge.h Merge.cpp -c ${CFLAGS}

Quicksort.o:Quicksort.h Quicksort.cpp
	${GCC} Quicksort.h Quicksort.cpp -c ${CFLAGS}

WQUUF.o:WQUUF.h WQUUF.cpp
	${GCC} WQUUF.h WQUUF.cpp -c ${CFLAGS}

DijkstraSP.o:DijkstraSP.h DijkstraSP.cpp
	${GCC} DijkstraSP.h DijkstraSP.cpp -c ${CFLAGS}

EdgeWeightedDiGraph.o:EdgeWeightedDiGraph.h EdgeWeightedDiGraph.cpp
	${GCC} EdgeWeightedDiGraph.h EdgeWeightedDiGraph.cpp -c ${CFLAGS}

IndexMinPQ.o:IndexMinPQ.h IndexMinPQ.cpp
	${GCC} IndexMinPQ.h IndexMinPQ.cpp -c ${CFLAGS}

DirectedEdge.o:DirectedEdge.h DirectedEdge.cpp
	${GCC} DirectedEdge.h DirectedEdge.cpp -c ${CFLAGS}

node.o:node.h node.cpp
	${GCC} node.h node.cpp -c ${CFLAGS}

clean:
	rm -rf *.a *.o *.gch main
