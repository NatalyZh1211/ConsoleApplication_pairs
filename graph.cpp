#include "graph.h"

// ���������� �������
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
// ���������� �����
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
 /* ��� ��������, ���������� �� �����, ����� ���������� �������� �������� ������� ��������� � ��������� ������� ������ (���� ���� �����, �� ������� �� 0).*/
 bool Graph::edgeExists(int v1, int v2)
 {
     return matrix[v1][v2] != 0;
 }

#define VERYBIGINT 1000000000
void Graph::findMinDistancesFloyd()
{
    int weights[SIZE][SIZE]; // ������� �����
    // ������������ �������
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // ���� �� ����� ���� ����� 0
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT; // ���� ����� ���
                }
                else {
                    weights[i][j] = matrix[i][j]; // ���� ����� ����
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) // �������� �� k
    {
        int ck = vertexes[k]; // ������� ����� �������
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
                    // �������� �������� �����
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    cout << "����:" << endl;
    for (int i = 0; i < vertexCount; i++)
        std::cout << "V" << i << ": " << vertexes_name[i] << ", ";
    cout << endl;
    
    cout << "������� ����������� ���� ����� ����� ���������:" << endl;

    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < vertexCount; j++)
            // ����� ���� ����������� ����� �� ������� '0'
        {
            std::cout << "V" << j << i << ": " << weights[j][vertexes[i]] << ", ";
        }
        cout << endl;
    }
    cout<<"����� ������ ���������� ������ ���� �����������:" << endl;
    for (int i = 0; i < vertexCount; i++)
    {
        for (int k = i+1; k < vertexCount; k++)
            // ����� ���� ����������� ����� �� ������� '0'
        {
            if (weights[k][vertexes[i]] <= 3)
            {
                cout << vertexes_name[k] << "<->" << vertexes_name[i] << endl;
             }
        }
        cout << endl;
    }
    
}

