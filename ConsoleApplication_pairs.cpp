#include "graph.h"

int main()
{
    setlocale(LC_ALL, "");
    Graph g;

    g.addVertex(0,"Anna");
    g.addVertex(1,"Sasha");
    g.addVertex(2,"Masha");
    g.addVertex(3,"Kolya");
    g.addVertex(4,"Nastya");
    g.addVertex(5,"Kostya");

    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 1);

    g.findMinDistancesFloyd(); 

    return 0;
}