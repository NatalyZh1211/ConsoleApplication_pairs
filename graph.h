#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;
#define SIZE 10

class Graph {
    public:
         Graph() {
             for(int i=0; i < SIZE; i++)
               for(int j=0; j < SIZE; j++)
                  matrix[i][j] = 0;
             vertexCount = 0;
         }

         void addVertex(int vnumber);
         void addVertex(int vnumber, string name);
         void addEdge(int v1, int v2, int weight);
         void deleteEdge(int v1, int v2);
         int getvertexCount();
         bool edgeExists(int v1, int v2);

         void findMinDistancesFloyd();

    private:
        int matrix[SIZE][SIZE]; // матрица смежности

        int vertexes[SIZE]; // хранилище вершин
        string vertexes_name[SIZE]; // хранилище вершин

        int vertexCount; // количество добавленных вершин
};

#endif // GRAPH_H
