#include "graph.h"

// добавление вершины
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount++] = vnumber;
}
void Graph::addVertex(int vnumber, string name)
{
    vertexes[vertexCount] = vnumber;
    vertexes_name[vertexCount] = name;
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}

void Graph::deleteEdge(int v1, int v2)
{
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}

 int Graph::getvertexCount()
 {
     return vertexCount;
 }
 /* Для проверки, существует ли ребро, нужно посмотреть значение элемента матрицы смежности с индексами номеров вершин (если есть ребро, он отличен от 0).*/
 bool Graph::edgeExists(int v1, int v2)
 {
     return matrix[v1][v2] != 0;
 }

#define VERYBIGINT 1000000000
void Graph::findMinDistancesFloyd()
{
    int weights[SIZE][SIZE]; // матрица путей
    // инициализаци матрицы
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // путь до самой себя равен 0
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT; // если ребра нет
                }
                else {
                    weights[i][j] = matrix[i][j]; // если ребро есть
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) // итерации по k
    {
        int ck = vertexes[k]; // возьмем номер вершины
        for (int i = 0; i < vertexCount; i++)
        {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++)
            {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // пересчет мматрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    cout << "Граф:" << endl;
    for (int i = 0; i < vertexCount; i++)
        std::cout << "V" << i << ": " << vertexes_name[i] << ", ";
    cout << endl;
    
    cout << "Матрица минимальных длин путей между вершинами:" << endl;

    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < vertexCount; j++)
            // вывод всех минимальных путей от вершины '0'
        {
            std::cout << "V" << j << i << ": " << weights[j][vertexes[i]] << ", ";
        }
        cout << endl;
    }
    cout<<"Между людьми расстояние меньше трех рукопожатий:" << endl;
    for (int i = 0; i < vertexCount; i++)
    {
        for (int k = i+1; k < vertexCount; k++)
            // вывод всех минимальных путей от вершины '0'
        {
            if (weights[k][vertexes[i]] <= 3)
            {
                cout << vertexes_name[k] << "<->" << vertexes_name[i] << endl;
             }
        }
        cout << endl;
    }
    
}

