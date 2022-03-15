#pragma once
#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include "PQueue.h"
using namespace std;

class Graph
{
private:
    int n; // количество вершин
    long int m; // количество ребер
    double* E; // матрица смежности
    double* Dist; // матрица кратчайших  расстояний
    int* CDist; // матрица количества кратчайших путей между вершинами 
    bool Or; // ориентированный или нет
public:
    Graph();
    Graph(int _n);
    Graph(int _n, int _m);
    Graph(int _n, int _m, string file);
    Graph(string file, int a);
    Graph(int _n, bool flag);
    Graph(int _n, double* _E);
    Graph(const Graph& tmp);
    ~Graph();
    int GetN();
    int GetM();

    void CreateFull(int _n);
    void CreateFullBi(int _n);
    void CreateBi(int _n);
    void CreateTree(int k, int _n);

    int* GetComponents();
    int ComponentQuantity();
    int MinVer(double* dist, bool* S, int maxdist);

    void AddN(int _n);
    void AddM(int _m);

    double* Floyd();

    void ADijkstra(int* up, double* dist, int start);
    void ADijkstraOMP(int* up, double* dist, int start, int thr);
    void AllDijkstra();
    void AllDijkstraOMP(int thr);

    double MerBet(int s);
    double MerBetF(int s);
    double MerBl(int s);
    double MerBlF(int s);
    double MerDeg(int s);

    //double MerDop(int s);
    //double MerDopOMP(int s);

    double MerBetOMP(int s, int thr);
    double MerBlOMP(int s, int thr);

    vector<int> MersBet();
    vector<int> MersBetF();
    vector<int> MersBl();
    vector<int> MersBlF();
    vector<int> MersDeg();

    //int* FloydDop();
    //vector<int> MersDop(int thr);
    //vector<int> MersDopOMP(int thr);

    vector<int> MersBetOMP(int thr);
    vector<int> MersBlOMP(int thr);

    friend istream& operator>>(istream& in, Graph& tmp) {
        cout << "number of vertices: ";
        in >> tmp.n;
        int m, a, b;
        cout << "number of ribs: ";
        cin >> m;
        tmp.E = new double[tmp.n * tmp.n]{ 0 };
        for (int i = 0; i < m; i++) {
            cin >> a >> b;//вершины
            a--;
            b--;
            cin >> tmp.E[a * tmp.n + b];//вес ребра
        }
        tmp.Or = false;
        for (int i = 0; i < tmp.n; i++) {
            for (int j = i + 1; j < tmp.n; j++) {
                if (tmp.E[i * tmp.n + j] != tmp.E[j * tmp.n + i]) {
                    tmp.Or = true;
                    break;
                }
            }
            if (tmp.Or == true)
                break;
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, const Graph& tmp) {
        for (int i = 0; i < tmp.n; i++) {
            for (int j = 0; j < tmp.n; j++)
                out << tmp.E[i * tmp.n + j] << " ";
            out << endl;
        }
        return out;
    }
};