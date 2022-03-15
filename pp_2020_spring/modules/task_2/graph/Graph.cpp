//#include "Graph.h"
#include <iostream>
#include <fstream>
#include <string>
#include "../../../modules/task_2/Graph/Graph.h"

Graph::Graph() {
    n = 0;
    m = 0;
    Or = true;
}
Graph::Graph(int _n) {
    n = _n;
    m = 0;
    E = new double[n * n]{ 0 };
    Or = true;
}
Graph::Graph(int _n, int _m) {
    n = _n;
    E = new double[n * n]{ 0 };
    Or = true;
    m = _m <= (n * n - n) ? _m : (n * n - n);
    int x, y;
    for (int i = 0; i < _m; i++) {
        do {
            x = rand() % n;
            y = rand() % n;
        } while ((E[x * n + y] != 0) || (x == y));
        E[x * n + y] = rand() % 20 + 1;
    }
}
Graph::Graph(int _n, int _m, string file) {
    n = _n;
    m = _m;
    E = new double[n * n]{ 0 };
    Or = true;
    int a, b;
    double w;
    std::ifstream fin(file);
    if (fin.is_open()) {
        for (int i = 0; i < _m; i++) {
            fin >> a >> b >> w;
            E[a * n + b] = w;
        }
    }
    fin.close();
}
Graph::Graph(string file, int z) {
    Or = true;
    int a, b;
    double w;
    std::ifstream fin(file);
    if (fin.is_open()) {
        if (z == 0) {
            fin >> n;
            E = new double[n * n]{ 0 };
            fin >> m;
            for (int i = 0; i < m; i++) {
                fin >> a >> b >> w;
                E[a * n + b] = w;
            }
        }
        else if (z == 1) {
            fin >> n;
            E = new double[n * n]{ 0 };
            fin >> m;
            for (int i = 0; i < m; i++) {
                fin >> a >> b;
                E[a * n + b] = 1;
            }
        }
        else if (z == 2) {
            fin >> n;
            E = new double[n * n]{ 0 };
            fin >> m;
            for (int i = 0; i < m; i++) {
                fin >> a >> b;
                E[a * n + b] = rand() % 20 - 10;
                if (E[a * n + b] < 0)
                    E[a * n + b] = 0;
            }
        }
    }
    fin.close();
}
Graph::Graph(int _n, bool flag) {
    n = _n;
    m = 0;
    E = new double[n * n]{ 0 };
    srand((unsigned int)time(0));
    Or = flag;
    if (flag == true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    E[i * n + j] = rand() % 20 - 10;
                    m++;
                }
                if (E[i * n + j] < 0) {
                    E[i * n + j] = 0;
                    m--;
                }
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                E[i * n + j] = E[j * n + i] = rand() % 20 - 10;
                m += 2;
                if (E[i * n + j] <= 0) {
                    E[i * n + j] = E[j * n + i] = 0;
                    m -= 2;
                }
            }
        }
    }
}
Graph::Graph(int _n, double* _E) {
    n = _n;
    m = 0;
    E = new double[n * n];
    for (int i = 0; i < n * n; i++) {
        E[i] = _E[i];
        if (E[i] > 0)
            m++;
    }
    Or = false;
    for (int i = 0; i < _n; i++) {
        for (int j = i + 1; j < _n; j++) {
            if (E[i * _n + j] != E[j * _n + i]) {
                Or = true;
                break;
            }
        }
        if (Or == true)
            break;
    }
}
Graph::Graph(const Graph& tmp) {
    n = tmp.n;
    m = tmp.m;
    E = new double[n * n];
    Or = tmp.Or;
    for (int i = 0; i < n * n; i++) {
        E[i] = tmp.E[i];
    }
}
Graph::~Graph() {
    n = 0;
    m = 0;
    delete[] E;
}
int Graph::GetN() {
    return n;
}
int Graph::GetM() {
    return m;
}

void Graph::ADijkstra(int* up, double* dist, int start) {
    if (ComponentQuantity() > 1) {
        cout << "more than 1 connectivity component" << endl;
        for (int i = 0; i < n; i++) {
            up[i] = -1;
            dist[i] = 0;
        }
        return;
    }
    bool *S = new bool[n];
    int i, j;
    double Max_Sum = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            Max_Sum += E[i * n + j];
    double* E1 = new double[n * n];
    for (i = 0; i < n * n; i++)
        E1[i] = E[i];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (E1[i * n + j] == 0)
                E1[i * n + j] = Max_Sum;
    for (i = 0; i < n; i++) {
        S[i] = false;
        up[i] = start;
        dist[i] = E1[start * n + i];
    }
    S[start] = true;
    up[start] = start;
    dist[start] = 0;
    for (i = 0; i < n; i++) {
        int w = 0;
        for (j = 1; j < n; j++) {
            if (!S[w]) {
                if (!S[j] && dist[j] <= dist[w])
                    w = j;
            }
            else w++;
        }
        S[w] = true;
        for (j = 1; j < n; j++)
            if (!S[j])
                if (dist[w] + E1[w * n + j] < dist[j]) {
                    dist[j] = dist[w] + E[w * n + j];
                    up[j] = w;
                }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == Max_Sum)
            dist[i] = -1;
    }
    delete[] S;
}

void Graph::ADijkstraOMP(int* up, double* dist, int start, int thr) {
    if (ComponentQuantity() > 1) {
        cout << "more than 1 connectivity component" << endl;
#pragma omp parallel for num_threads(thr)
        for (int i = 0; i < n; i++) {
            up[i] = -1;
            dist[i] = 0;
        }
        return;
    }
    bool* S = new bool[n];
    int i, j;
    double Max_Sum = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            Max_Sum += E[i * n + j];
    double* E1 = new double[n * n];
#pragma omp parallel for num_threads(thr)
    for (i = 0; i < n * n; i++) {
        if (E[i] != 0) {
            E1[i] = E[i];
        }
        else {
            E1[i] = Max_Sum;
        }
    }
#pragma omp parallel for num_threads(thr)
    for (i = 0; i < n; i++) {
        S[i] = false;
        up[i] = start;
        dist[i] = E1[start * n + i];
    }
    S[start] = true;
    up[start] = start;
    dist[start] = 0;
    for (i = 0; i < n; i++) {
        int w = 0;
        for (j = 1; j < n; j++) {
            if (!S[w]) {
                if (!S[j] && dist[j] <= dist[w])
                    w = j;
            }
            else {
                w++;
            }
        }
        S[w] = true;
#pragma omp parallel for num_threads(thr)
        for (j = 0; j < n; j++)
            if ((!S[j]) && (dist[w] + E1[w * n + j] < dist[j])) {
                dist[j] = dist[w] + E1[w * n + j];
                up[j] = w;
            }
    }
#pragma omp parallel for num_threads(thr)
    for (int i = 0; i < n; i++) {
        if (dist[i] == Max_Sum)
            dist[i] = -1;
    }
    delete[] S;
}


int* Graph::GetComponents() {
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i;
    if (Or = false) {
        for (int i = 0; i < n; i++) { //для неориентированного графа
            for (int j = i + 1; j < n; j++) {
                if (E[i * n + j] > 0) {
                    if (arr[i] < arr[j])
                        arr[j] = arr[i];
                    else if (arr[i] > arr[j])
                        arr[i] = arr[j];
                }
            }
        }
    }
    else {
        for (int i = 0; i < n; i++) { //для ориентированного графа
            for (int j = i + 1; j < n; j++) {
                if ((E[i * n + j] > 0) || (E[j * n + i] > 0)) {
                    if (arr[i] < arr[j])
                        arr[j] = arr[i];
                    else if (arr[i] > arr[j])
                        arr[i] = arr[j];
                }
            }
        }
    }
    return arr;
}

int Graph::ComponentQuantity() {
    int* arr = this->GetComponents();
    int comp = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == i)
            comp++;
    return comp;
}

double* Graph::Floyd() {
    double* arr = new double[n * n];
    CDist = new int[n * n];
    double sum = 0;
    for (int i = 0; i < n * n; i++) {
        sum += E[i];
        CDist[i] = 1;
    }

    for (int i = 0; i < n * n; i++) {
        if (E[i] == 0) {
            if (i / n == i % n)
                arr[i] = 0;
            else
                arr[i] = sum;
        }
        else
            arr[i] = E[i];
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if ((i != j) && (i != k) && (j != k)) {
                    if ((arr[i * n + k] + arr[k * n + j]) == arr[i * n + j]) {
                        CDist[i * n + j] += CDist[i * n + k] * CDist[k * n + j];
                    }
                    if ((arr[i * n + k] + arr[k * n + j]) < arr[i * n + j]) {
                        arr[i * n + j] = arr[i * n + k] + arr[k * n + j];
                        CDist[i * n + j] = CDist[i * n + k] * CDist[k * n + j];
                    }
                }
            }
    for (int i = 0; i < n * n; i++) {
        if (arr[i] == sum) {
            arr[i] = -1;
            CDist[i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        CDist[i * n + i] = 0;
    }
    return arr;
}

void Graph::AllDijkstra() {
    Dist = new double[n * n];
    CDist = new int[n * n]{ 0 };
    /*if (ComponentQuantity() > 1) {
        cout << "more than 1 connectivity component" << endl;
        return;
    }*/
    int i, j;
    double Max_Sum = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            Max_Sum += E[i * n + j];
    double* E1 = new double[n * n];
    for (i = 0; i < n * n; i++)
        E1[i] = E[i];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (E1[i * n + j] == 0)
                E1[i * n + j] = Max_Sum;
    for (int start = 0; start < n; start++) {
        bool *S = new bool[n];
        for (i = 0; i < n; i++) {
            S[i] = false;
            Dist[start * n + i] = E1[start * n + i];
            if (Dist[start * n + i] < Max_Sum)
                CDist[start * n + i] = 1;
        }
        S[start] = true;
        Dist[start * n + start] = 0;
        CDist[start * n + start] = 1;
        for (i = 0; i < n; i++) {
            int w = 0;
            for (j = 1; j < n; j++) {
                if (!S[w]) {
                    if (!S[j] && Dist[start * n + j] <= Dist[start * n + w])
                        w = j;
                }
                else w++;
            }
            if (Dist[start * n + w] == Max_Sum)
                break;
            S[w] = true;
            for (j = 0; j < n; j++) {
                if (!S[j]) {
                    if (Dist[start * n + w] + E1[w * n + j] == Dist[start * n + j]) {
                        CDist[start * n + j] += CDist[start * n + w];
                    }
                    else if (Dist[start * n + w] + E1[w * n + j] < Dist[start * n + j]) {
                        Dist[start * n + j] = Dist[start * n + w] + E[w * n + j];
                        CDist[start * n + j] = CDist[start * n + w];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (Dist[start * n + i] == Max_Sum) {
                Dist[start * n + i] = -1;
                CDist[start * n + i] = 0;
            }
        }
        delete[] S;
        CDist[start * n + start] = 0;
    }
}

void Graph::AllDijkstraOMP(int thr) {
    Dist = new double[n * n];
    CDist = new int[n * n]{ 0 };
    double Max_Sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Max_Sum += E[i * n + j];
    double* E1 = new double[n * n];
#pragma omp parallel for num_threads(thr)
    for (int i = 0; i < n * n; i++)
        E1[i] = E[i];
#pragma omp parallel for num_threads(thr)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (E1[i * n + j] == 0)
                E1[i * n + j] = Max_Sum;
#pragma omp parallel for num_threads(thr)
    for (int start = 0; start < n; start++) {
        bool *S = new bool[n];
        for (int i = 0; i < n; i++) {
            S[i] = false;
            Dist[start * n + i] = E1[start * n + i];
            if (Dist[start * n + i] < Max_Sum)
                CDist[start * n + i] = 1;
        }
        S[start] = true;
        Dist[start * n + start] = 0;
        CDist[start * n + start] = 1;
        for (int i = 0; i < n; i++) {
            int w = 0;
            for (int j = 1; j < n; j++) {
                if (!S[w]) {
                    if (!S[j] && Dist[start * n + j] <= Dist[start * n + w])
                        w = j;
                }
                else w++;
            }
            if (Dist[start * n + w] == Max_Sum)
                break;
            S[w] = true;
            for (int j = 0; j < n; j++) {
                if (!S[j]) {
                    if (Dist[start * n + w] + E1[w * n + j] == Dist[start * n + j]) {
                        CDist[start * n + j] += CDist[start * n + w];
                    }
                    else if (Dist[start * n + w] + E1[w * n + j] < Dist[start * n + j]) {
                        Dist[start * n + j] = Dist[start * n + w] + E[w * n + j];
                        CDist[start * n + j] = CDist[start * n + w];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (Dist[start * n + i] == Max_Sum) {
                Dist[start * n + i] = -1;
                CDist[start * n + i] = 0;
            }
        }
        delete[] S;
        CDist[start * n + start] = 0;
    }
}

double Graph::MerBet(int s) {
    double mera = 0;
    AllDijkstra();
    for (int i = 0; i < n; i++) {
        if (CDist[i * n + s] != 0) {
            for (int j = 0; j < n; j++) {
                //if ((s != i) && (s != j) && (i != j) && (Dist[i * n + j] == (Dist[i * n + s] + Dist[s * n + j])) && (CDist[i * n + j] != 0)) {
                if ((CDist[s * n + j] != 0) && (CDist[i * n + j] != 0) && (Dist[i * n + j] == (Dist[i * n + s] + Dist[s * n + j]))) {
                    mera += (double)(CDist[i * n + s] * CDist[s * n + j]) / (double)(CDist[i * n + j]);
                }
            }
        }
    }
    delete[] Dist;
    delete[] CDist;
    return mera;
}

double Graph::MerBetF(int s) {
    double mera = 0;
    Dist = Floyd();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((s != i) && (s != j) && (i != j) && (Dist[i * n + j] == (Dist[i * n + s] + Dist[s * n + j])) && (CDist[i * n + j] != 0)) {
                mera += (double)(CDist[i * n + s] * CDist[s * n + j]) / (double)(CDist[i * n + j]);
            }
        }
    }
    /*cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << Dist[i * n + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << CDist[i * n + j] << " ";
        }
        cout << endl;
    }
    cout << endl;*/
    delete[] Dist;
    delete[] CDist;
    return mera;
}

double Graph::MerBl(int s) {
    double mera = 0;
    int* up = new int[n];
    double* dist = new double[n];
    ADijkstra(up, dist, s);
    for (int i = 0; i < n; i++) {
        if (dist[i] > 0)
            mera += (double)dist[i];
    }
    mera = 1.0 / mera;
    delete[] dist;
    delete[] up;
    return mera;
}
double Graph::MerBlF(int s) {
    double mera = 0;
    Dist = Floyd();
    for (int i = 0; i < n; i++) {
        if (Dist[s * n + i] > 0)
            mera += (double)Dist[s * n + i];
    }
    mera = 1.0 / mera;
    delete[] Dist;
    delete[] CDist;
    return mera;
}

double Graph::MerDeg(int s) {
    double mera = 0;
    for (int i = 0; i < n; i++) {
        if (E[s * n + i] > 0)
            mera++;
    }
    return mera;
}

double Graph::MerBetOMP(int s, int thr) {
    double mera = 0;
    AllDijkstraOMP(thr);
    AllDijkstra();
    for (int i = 0; i < n; i++) {
        if (CDist[i * n + s] != 0) {
            for (int j = 0; j < n; j++) {
                //if ((s != i) && (s != j) && (i != j) && (Dist[i * n + j] == (Dist[i * n + s] + Dist[s * n + j])) && (CDist[i * n + j] != 0)) {
                if ((CDist[s * n + j] != 0) && (CDist[i * n + j] != 0) && (Dist[i * n + j] == (Dist[i * n + s] + Dist[s * n + j]))) {
                    mera += (double)(CDist[i * n + s] * CDist[s * n + j]) / (double)(CDist[i * n + j]);
                }
            }
        }
    }
    delete[] Dist;
    delete[] CDist;
    return mera;
}
double Graph::MerBlOMP(int s, int thr) {
    double mera = 0;
    int* up = new int[n];
    double* dist = new double[n];
    ADijkstraOMP(up, dist, s, thr);
    for (int i = 0; i < n; i++) {
        if (dist[i] > 0)
            mera += (double)dist[i];
    }
    mera = 1.0 / mera;
    delete[] dist;
    delete[] up;
    return mera;
}

vector<int> Graph::MersBet() {
    vector<int> vert;
    double mera = 0;
    double* meras = new double[n] {0};
    AllDijkstra();
    for (int s = 0; s < n; s++) {
        for (int i = 0; i < n; i++) {
            if (CDist[i * n + s] != 0) {
                for (int j = 0; j < n; j++) {
                    //if ((s != i) && (s != j) && (i != j) && (Dist[i * n + j] == (Dist[i * n + s] + Dist[s * n + j])) && (CDist[i * n + j] != 0)) {
                    if ((CDist[s * n + j] != 0) && (CDist[i * n + j] != 0) && (Dist[i * n + j] == (Dist[i * n + s] + Dist[s * n + j]))) {
                        meras[s] += (double)(CDist[i * n + s] * CDist[s * n + j]) / (double)(CDist[i * n + j]);
                    }
                }
            }
        }
        if (meras[s] > mera)
            mera = meras[s];
    }
    for (int i = 0; i < n; i++) {
        if (meras[i] == mera)
            vert.push_back(i);
    }
    delete[] Dist;
    delete[] CDist;
    delete[] meras;
    return vert;
}
vector<int> Graph::MersBetF() {
    vector<int> vert;
    double mera = 0;
    double* meras = new double[n] {0};
    Dist = Floyd();
    for (int s = 0; s < n; s++) {
        for (int i = 0; i < n; i++) {
            if (CDist[i * n + s] != 0) {
                for (int j = 0; j < n; j++) {
                    //if ((s != i) && (s != j) && (i != j) && (Dist[i * n + j] == (Dist[i * n + s] + Dist[s * n + j])) && (CDist[i * n + j] != 0)) {
                    if ((CDist[s * n + j] != 0) && (CDist[i * n + j] != 0) && (Dist[i * n + j] == (Dist[i * n + s] + Dist[s * n + j]))) {
                        meras[s] += (double)(CDist[i * n + s] * CDist[s * n + j]) / (double)(CDist[i * n + j]);
                    }
                }
            }
        }
        if (meras[s] > mera)
            mera = meras[s];
    }
    for (int i = 0; i < n; i++) {
        if (meras[i] == mera)
            vert.push_back(i);
    }
    delete[] Dist;
    delete[] CDist;
    delete[] meras;
    return vert;
}
vector<int> Graph::MersBl() {
    double mera = 0;
    vector<int> vert;
    double* meras = new double[n] {0};
    AllDijkstra();
    for (int s = 0; s < n; s++) {
        for (int i = 0; i < n; i++) {
            if (Dist[s * n + i] > 0)
                meras[s] += (double)Dist[s * n + i];
        }
        meras[s] = 1.0 / meras[s];
        if (meras[s] > mera) {
            mera = meras[s];
        }
    }
    for (int i = 0; i < n; i++) {
        if (meras[i] == mera)
            vert.push_back(i);
    }
    delete[] Dist;
    delete[] CDist;
    delete[] meras;
    return vert;
}
vector<int> Graph::MersBlF() {
    double mera = 0;
    vector<int> vert;
    double* meras = new double[n] {0};
    Dist = Floyd();
    for (int s = 0; s < n; s++) {
        for (int i = 0; i < n; i++) {
            if (Dist[s * n + i] > 0)
                meras[s] += (double)Dist[s * n + i];
        }
        meras[s] = 1.0 / meras[s];
        if (meras[s] > mera) {
            mera = meras[s];
        }
    }
    for (int i = 0; i < n; i++) {
        if (meras[i] == mera)
            vert.push_back(i);
    }
    delete[] Dist;
    delete[] CDist;
    delete[] meras;
    return vert;
}
vector<int> Graph::MersDeg() {
    double mera = 0;
    vector<int> vert;
    double* meras = new double[n] {0};
    for (int s = 0; s < n; s++) {
        for (int i = 0; i < n; i++) {
            if (E[s * n + i] > 0)
                meras[s]++;
        }
        if (meras[s] > mera) {
            mera = meras[s];
        }
    }
    for (int i = 0; i < n; i++) {
        if (meras[i] == mera)
            vert.push_back(i);
    }
    delete[] meras;
    return vert;
}

vector<int> Graph::MersBetOMP(int thr) {
    vector<int> vert;
    double mera = 0;
    double* meras = new double[n] {0};
    AllDijkstraOMP(thr);
    for (int s = 0; s < n; s++) {
        for (int i = 0; i < n; i++) {
            if (CDist[i * n + s] != 0) {
                for (int j = 0; j < n; j++) {
                    //if ((s != i) && (s != j) && (i != j) && (Dist[i * n + j] == (Dist[i * n + s] + Dist[s * n + j])) && (CDist[i * n + j] != 0)) {
                    if ((CDist[s * n + j] != 0) && (CDist[i * n + j] != 0) && (Dist[i * n + j] == (Dist[i * n + s] + Dist[s * n + j]))) {
                        meras[s] += (double)(CDist[i * n + s] * CDist[s * n + j]) / (double)(CDist[i * n + j]);
                    }
                }
            }
        }
        if (meras[s] > mera)
            mera = meras[s];
    }
    for (int i = 0; i < n; i++) {
        if (meras[i] == mera)
            vert.push_back(i);
    }
    delete[] Dist;
    delete[] CDist;
    delete[] meras;
    return vert;
}
vector<int> Graph::MersBlOMP(int thr) {
    double mera = 0;
    vector<int> vert;
    double* meras = new double[n] {0};
    AllDijkstraOMP(thr);
    for (int s = 0; s < n; s++) {
        for (int i = 0; i < n; i++) {
            if (Dist[s * n + i] > 0)
                meras[s] += (double)Dist[s * n + i];
        }
        meras[s] = 1.0 / meras[s];
        if (meras[s] > mera) {
            mera = meras[s];
        }
    }
    for (int i = 0; i < n; i++) {
        if (meras[i] == mera)
            vert.push_back(i);
    }
    delete[] Dist;
    delete[] CDist;
    delete[] meras;
    return vert;
}

void Graph::AddN(int _n) {
    double* E1 = new double[(n + _n) * (n + _n)]{ 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            E1[i * (n + _n) + j] = E[i * n + j];
        }
    }
    E = E1;
    n += _n;
}
void Graph::AddM(int _m) {
    int x, y;
    if ((_m + m) > (n * n - n))
        _m = (n * n - n) - m;
    for (int i = 0; i < _m; i++) {
        do {
            x = rand() % n;
            y = rand() % n;
        } while ((E[x * n + y] != 0) || (x == y));
        E[x * n + y] = rand() % 10 + 1;
    }
    m += _m;
}

void Graph::CreateFull(int _n) {
    n = _n;
    m = n * n - n;
    E = new double[n * n]{ 0 };
    Or = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            E[i * n + j] = E[j * n + i] = rand() % 10 + 1;
            m += 2;
        }
    }
}
void Graph::CreateFullBi(int _n) {
    n = _n;
    E = new double[n * n]{ 0 };
    m = 0;
    Or = false;
    int n1 = rand() % (n - 1) + 1;
    for (int i = 0; i < n1; i++) {
        for (int j = n1; j < n; j++) {
            E[i * n + j] = E[j * n + i] = rand() % 10 + 1;
            m += 2;
        }
    }
}
void Graph::CreateBi(int _n) {
    n = _n;
    E = new double[n * n]{ 0 };
    m = 0;
    Or = false;
    int n1 = rand() % (n - 1) + 1;
    for (int i = 0; i < n1; i++) {
        for (int j = n1; j < n; j++) {
            E[i * n + j] = E[j * n + i] = rand() % 20 - 10;
            m += 2;
            if (E[i * n + j] <= 0) {
                E[i * n + j] = E[j * n + i] = 0;
                m -= 2;
            }
        }
    }

}
void Graph::CreateTree(int k, int _n) {
    n = _n;
    E = new double[n * n]{ 0 };
    m = 0;
    Or = false;
    for (int i = n - 1; i > 0; i--) {
        int x = i % k == 0 ? i / k - 1 : i / k;
        E[i * n + x] = E[x * n + i] = rand() % 10 + 1;
        m += 2;
    }
}

