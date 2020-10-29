#pragma once
#include <iostream>
#include "PQueue.h"
using namespace std;

class Graph
{
private:
    int n;//количество вершин
    int* E;//матрица смежности
public:
    Graph();
    Graph(int _n);
    Graph(int _n, int* _E);
    Graph(const Graph& tmp);
    ~Graph();
    int GetN();
    int* GetComponents();
    int ComponentQuantity();

    int* Floyd();

    static void ADijkstra(const Graph& tmp, int* up, double* dist, int start);

    friend istream& operator>>(istream& in, Graph& tmp)
    {
        cout << "number of vertices: ";
        in >> tmp.n;
        int m, a, b;
        cout << "number of ribs: ";
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            cin << a << b;//вершины
            in >> tmp.E[a * n + b];//вес ребра
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, const Graph& tmp)
    {
        for (int i = 0; i < tmp.n; i++)
        {
            for (int j = 0; j < tmp.n; j++)
                out << tmp.E[i * n + j] << " ";
            out << endl;
        }
        return out;
    }
};