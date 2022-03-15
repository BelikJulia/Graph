#include "Graph.h"
#include <omp.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

/*void File(const char* file1) {
    setlocale(LC_ALL, "Rus"); // ����������� ������ ���� ������. ������������ ������� � ������� 
    fstream file(file1);
    if (!file.is_open()) {
        file.open(file1, fstream::out);
    }
    char symbols[200];
    fstream out("out.txt", ios::trunc); //��������� ����
    while (!file.eof()) {
        file >> symbols;
        for (int i = 0; i < 200; i++)
        {
            if (symbols[i] = '.') {
                symbols[i] = ',';
            }
        }
        out << symbols; //����� ������ �� ��������� ����
    }
    file.close();
    out.close();
    remove(file1);  //������� ������
    rename("out.txt", file1); //�������� ������ ���������
}*/

double TestnMersBet(int n) {
    int m = n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBet();
    double end = omp_get_wtime();
    return end - start;
}
double Test2nMersBet(int n) {
    int m = 2 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBet();
    double end = omp_get_wtime();
    return end - start;
}
double Test3nMersBet(int n) {
    int m = 3 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBet();
    double end = omp_get_wtime();
    return end - start;
}
double Test4nMersBet(int n) {
    int m = 4 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBet();
    double end = omp_get_wtime();
    return end - start;
}

double TestnMersBetOMP(int n, int thr) {
    int m = n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}
double Test2nMersBetOMP(int n, int thr) {
    int m = 2 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}
double Test3nMersBetOMP(int n, int thr) {
    int m = 3 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}
double Test4nMersBetOMP(int n, int thr) {
    int m = 4 * 
n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}

double TestnMersBetF(int n) {
    int m = n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetF();
    double end = omp_get_wtime();
    return end - start;
}
double Test2nMersBetF(int n) {
    int m = 2 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetF();
    double end = omp_get_wtime();
    return end - start;
}
double Test3nMersBetF(int n) {
    int m = 3 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetF();
    double end = omp_get_wtime();
    return end - start;
}
double Test4nMersBetF(int n) {
    int m = 4 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetF();
    double end = omp_get_wtime();
    return end - start;
}

double TestnMersBl(int n) {
    int m = n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBl();
    double end = omp_get_wtime();
    return end - start;
}
double Test2nMersBl(int n) {
    int m = 2 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBl();
    double end = omp_get_wtime();
    return end - start;
}
double Test3nMersBl(int n) {
    int m = 3 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBl();
    double end = omp_get_wtime();
    return end - start;
}
double Test4nMersBl(int n) {
    int m = 4 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBl();
    double end = omp_get_wtime();
    return end - start;
}

double TestnMersBlF(int n) {
    int m = n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    double end = omp_get_wtime();
    return end - start;
}
double Test2nMersBlF(int n) {
    int m = 2 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    double end = omp_get_wtime();
    return end - start;
}
double Test3nMersBlF(int n) {
    int m = 3 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    double end = omp_get_wtime();
    return end - start;
}
double Test4nMersBlF(int n) {
    int m = 4 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    double end = omp_get_wtime();
    return end - start;
}

double TestnMersBlOMP(int n, int thr) {
    int m = n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}
double Test2nMersBlOMP(int n, int thr) {
    int m = 2 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}
double Test3nMersBlOMP(int n, int thr) {
    int m = 3 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}
double Test4nMersBlOMP(int n, int thr) {
    int m = 4 * n;
    Graph gr = Graph(n, m);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}

double TestFullMersBet(int n) {
    Graph gr = Graph();
    gr.CreateFull(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBet();
    double end = omp_get_wtime();
    return end - start;
}
double TestFullMersBetF(int n) {
    Graph gr = Graph();
    gr.CreateFull(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetF();
    double end = omp_get_wtime();
    return end - start;
}
double TestFullMersBetOMP(int n, int thr) {
    Graph gr = Graph();
    gr.CreateFull(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}
double TestFullMersBl(int n) {
    Graph gr = Graph();
    gr.CreateFull(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBl();
    double end = omp_get_wtime();
    return end - start;
}
double TestFullMersBlF(int n) {
    Graph gr = Graph();
    gr.CreateFull(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    double end = omp_get_wtime();
    return end - start;
}
double TestFullMersBlOMP(int n, int thr) {
    Graph gr = Graph();
    gr.CreateFull(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}

double TestFullBiMersBet(int n) {
    Graph gr = Graph();
    gr.CreateFullBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBet();
    double end = omp_get_wtime();
    return end - start;
}
double TestFullBiMersBetF(int n) {
    Graph gr = Graph();
    gr.CreateFullBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetF();
    double end = omp_get_wtime();
    return end - start;
}
double TestFullBiMersBetOMP(int n, int thr) {
    Graph gr = Graph();
    gr.CreateFullBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}
double TestFullBiMersBl(int n) {
    Graph gr = Graph();
    gr.CreateFullBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBl();
    double end = omp_get_wtime();
    return end - start;
}
double TestFullBiMersBlF(int n) {
    Graph gr = Graph();
    gr.CreateFullBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    double end = omp_get_wtime();
    return end - start;
}
double TestFullBiMersBlOMP(int n, int thr) {
    Graph gr = Graph();
    gr.CreateFullBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}

double TestBiMersBet(int n) {
    Graph gr = Graph();
    gr.CreateBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBet();
    double end = omp_get_wtime();
    return end - start;
}
double TestBiMersBetF(int n) {
    Graph gr = Graph();
    gr.CreateBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetF();
    double end = omp_get_wtime();
    return end - start;
}
double TestBiMersBetOMP(int n, int thr) {
    Graph gr = Graph();
    gr.CreateBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}
double TestBiMersBl(int n) {
    Graph gr = Graph();
    gr.CreateBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBl();
    double end = omp_get_wtime();
    return end - start;
}
double TestBiMersBlF(int n) {
    Graph gr = Graph();
    gr.CreateBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    double end = omp_get_wtime();
    return end - start;
}
double TestBiMersBlOMP(int n, int thr) {
    Graph gr = Graph();
    gr.CreateBi(n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}

double TestTreeMersBet(int n, int d) {
    Graph gr = Graph();
    gr.CreateTree(d, n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBet();
    double end = omp_get_wtime();
    return end - start;
}
double TestTreeMersBetF(int n, int d) {
    Graph gr = Graph();
    gr.CreateTree(d, n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetF();
    double end = omp_get_wtime();
    return end - start;
}
double TestTreeMersBetOMP(int n, int d, int thr) {
    Graph gr = Graph();
    gr.CreateTree(d, n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}
double TestTreeMersBl(int n, int d) {
    Graph gr = Graph();
    gr.CreateTree(d, n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBl();
    double end = omp_get_wtime();
    return end - start;
}
double TestTreeMersBlF(int n, int d) {
    Graph gr = Graph();
    gr.CreateTree(d, n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    double end = omp_get_wtime();
    return end - start;
}
double TestTreeMersBlOMP(int n, int d, int thr) {
    Graph gr = Graph();
    gr.CreateTree(d, n);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}

double TestTreeMersBetFile(string file, int z, int thr) {
    Graph gr = Graph(file, z);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBetOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}
double TestTreeMersBlFile(string file, int z, int thr) {
    Graph gr = Graph(file, z);
    double start = omp_get_wtime();
    vector<int> vert = gr.MersBlOMP(thr);
    double end = omp_get_wtime();
    return end - start;
}

void TestMersBetn() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBetn.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestnMersBetF(n);
        ptr[i] = time;
        time = TestnMersBet(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestnMersBetOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = TestnMersBetOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBet2n() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBet2n.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = Test2nMersBetF(n);
        ptr[i] = time;
        time = Test2nMersBet(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = Test2nMersBetOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = Test2nMersBetOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBet3n() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBet3n.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = Test3nMersBetF(n);
        ptr[i] = time;
        time = Test3nMersBet(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = Test3nMersBetOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = Test3nMersBetOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBet4n() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBet4n.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = Test4nMersBetF(n);
        ptr[i] = time;
        time = Test4nMersBet(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = Test4nMersBetOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = Test4nMersBetOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}

void TestMersBln() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBln.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestnMersBlF(n);
        ptr[i] = time;
        time = TestnMersBl(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestnMersBlOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = TestnMersBlOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBl2n() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBl2n.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = Test2nMersBlF(n);
        ptr[i] = time;
        time = Test2nMersBl(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = Test2nMersBlOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = Test2nMersBlOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBl3n() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBl3n.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = Test3nMersBlF(n);
        ptr[i] = time;
        time = Test3nMersBl(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = Test3nMersBlOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = Test3nMersBlOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBl4n() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBl4n.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = Test4nMersBlF(n);
        ptr[i] = time;
        time = Test4nMersBl(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = Test4nMersBlOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = Test4nMersBlOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}

void TestMersBetFull() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBetFull.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestFullMersBetF(n);
        ptr[i] = time;
        time = TestFullMersBet(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestFullMersBetOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = TestFullMersBetOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBetFullBi() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBetFullBi.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestFullBiMersBetF(n);
        ptr[i] = time;
        time = TestFullBiMersBet(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestFullBiMersBetOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = TestFullBiMersBetOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBetBi() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBetBi.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestBiMersBetF(n);
        ptr[i] = time;
        time = TestBiMersBet(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestBiMersBetOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = TestBiMersBetOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBetTree1() { // ��� �������� � = 1 
    ofstream out;       // ������ ��� ������
    out.open("MersBetTree1.txt"); // ����� ��������� ���� � ���� �������
    int k = 1;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestTreeMersBetF(n, k);
        ptr[i] = time;
        time = TestTreeMersBet(n, k);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestTreeMersBetOMP(n, k, j);
            ptr[5 * j + i] = time;
        }
        time = TestTreeMersBetOMP(n, k, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBetTree2() { // ��� �������� � = 1 
    ofstream out;       // ������ ��� ������
    out.open("MersBetTree2.txt"); // ����� ��������� ���� � ���� �������
    int k = 2;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestTreeMersBetF(n, k);
        ptr[i] = time;
        time = TestTreeMersBet(n, k);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestTreeMersBetOMP(n, k, j);
            ptr[5 * j + i] = time;
        }
        time = TestTreeMersBetOMP(n, k, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBetTree3() { // ��� �������� � = 1 
    ofstream out;       // ������ ��� ������
    out.open("MersBetTree3.txt"); // ����� ��������� ���� � ���� �������
    int k = 3;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestTreeMersBetF(n, k);
        ptr[i] = time;
        time = TestTreeMersBet(n, k);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestTreeMersBetOMP(n, k, j);
            ptr[5 * j + i] = time;
        }
        time = TestTreeMersBetOMP(n, k, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBetTree4() { // ��� �������� � = 1 
    ofstream out;       // ������ ��� ������
    out.open("MersBetTree4.txt"); // ����� ��������� ���� � ���� �������
    int k = 4;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestTreeMersBetF(n, k);
        ptr[i] = time;
        time = TestTreeMersBet(n, k);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestTreeMersBetOMP(n, k, j);
            ptr[5 * j + i] = time;
        }
        time = TestTreeMersBetOMP(n, k, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}

void TestMersBlFull() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBlFull.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestFullMersBlF(n);
        ptr[i] = time;
        time = TestFullMersBl(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestFullMersBlOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = TestFullMersBlOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBlFullBi() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBlFullBi.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestFullBiMersBlF(n);
        ptr[i] = time;
        time = TestFullBiMersBl(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestFullBiMersBlOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = TestFullBiMersBlOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBlBi() { // ������� �� 5 * 7 ������
    ofstream out;       // ������ ��� ������
    out.open("MersBlBi.txt"); // ����� ��������� ���� � ���� �������
    srand((unsigned)time(NULL));
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestBiMersBlF(n);
        ptr[i] = time;
        time = TestBiMersBl(n);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestBiMersBlOMP(n, j);
            ptr[5 * j + i] = time;
        }
        time = TestBiMersBlOMP(n, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBlTree1() { // ��� �������� � = 1 
    ofstream out;       // ������ ��� ������
    out.open("MersBlTree1.txt"); // ����� ��������� ���� � ���� �������
    int k = 1;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestTreeMersBlF(n, k);
        ptr[i] = time;
        time = TestTreeMersBl(n, k);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestTreeMersBlOMP(n, k, j);
            ptr[5 * j + i] = time;
        }
        time = TestTreeMersBlOMP(n, k, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBlTree2() { // ��� �������� � = 1 
    ofstream out;       // ������ ��� ������
    out.open("MersBlTree2.txt"); // ����� ��������� ���� � ���� �������
    int k = 2;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestTreeMersBlF(n, k);
        ptr[i] = time;
        time = TestTreeMersBl(n, k);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestTreeMersBlOMP(n, k, j);
            ptr[5 * j + i] = time;
        }
        time = TestTreeMersBlOMP(n, k, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBlTree3() { // ��� �������� � = 1 
    ofstream out;       // ������ ��� ������
    out.open("MersBlTree3.txt"); // ����� ��������� ���� � ���� �������
    int k = 3;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestTreeMersBlF(n, k);
        ptr[i] = time;
        time = TestTreeMersBl(n, k);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestTreeMersBlOMP(n, k, j);
            ptr[5 * j + i] = time;
        }
        time = TestTreeMersBlOMP(n, k, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}
void TestMersBlTree4() { // ��� �������� � = 1 
    ofstream out;       // ������ ��� ������
    out.open("MersBlTree4.txt"); // ����� ��������� ���� � ���� �������
    int k = 4;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[5 * 7]{ 0.0 };
    int n = 100;

    for (i = 0; i < 5; i++) {
        double time = TestTreeMersBlF(n, k);
        ptr[i] = time;
        time = TestTreeMersBl(n, k);
        ptr[5 * 1 + i] = time;
        for (int j = 2; j < 6; j++) {
            time = TestTreeMersBlOMP(n, k, j);
            ptr[5 * j + i] = time;
        }
        time = TestTreeMersBlOMP(n, k, 8);
        ptr[5 * 6 + i] = time;
        n *= 2;
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++)
            out << ptr[i * 5 + j] << ' '; // ���������� ������� � �����
        out << '\n';
    }
    cout << "���� �������" << endl;
}

void TestMersBetbio_CE_GT() { // ������ �� ����� ����� ������ � ����� � �� �������� ������
    ofstream out;       // ������ ��� ������
    out.open("MersBetbio_CE_GT.txt");
    int z = 0;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[6 * 1]{ 0.0 };
    int* thrs = new int[6]{ 1, 2, 3, 4, 6, 8 };
    //int n = 100;
    string file = "E:\\Progi\\Graph\\bio-CE-GT.txt";

    for (i = 0; i < 6; i++) {
        double time = TestTreeMersBetFile(file, z, thrs[i]);
        ptr[i] = time;
    }

    for (j = 0; j < 6; j++)
        out << ptr[j] << ' '; // ���������� ������� � �����
    out << '\n';
    cout << "���� �������" << endl;
}
void TestMersBlbio_CE_GT() { // ������ �� ����� ����� ������ � ����� � �� �������� ������
    ofstream out;       // ������ ��� ������
    out.open("MersBlbio_CE_GT.txt");
    int z = 0;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[6 * 1]{ 0.0 };
    int* thrs = new int[6]{ 1, 2, 3, 4, 6, 8 };
    //int n = 100;
    string file = "E:\\Progi\\Graph\\bio-CE-GT.txt";

    for (i = 0; i < 6; i++) {
        double time = TestTreeMersBlFile(file, z, thrs[i]);
        ptr[i] = time;
    }

    for (j = 0; j < 6; j++)
        out << ptr[j] << ' '; // ���������� ������� � �����
    out << '\n';
    cout << "���� �������" << endl;
}
void TestMersBetbio_CE_HT() { // ������ �� ����� ����� ������ � ����� � �� �������� ������
    ofstream out;       // ������ ��� ������
    out.open("MersBetbio_CE_HT.txt");
    int z = 0;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[6 * 1]{ 0.0 };
    int* thrs = new int[6]{ 1, 2, 3, 4, 6, 8 };
    //int n = 100;
    string file = "E:\\Progi\\Graph\\bio-CE-HT.txt";

    for (i = 0; i < 6; i++) {
        double time = TestTreeMersBetFile(file, z, thrs[i]);
        ptr[i] = time;
    }

    for (j = 0; j < 6; j++)
        out << ptr[j] << ' '; // ���������� ������� � �����
    out << '\n';
    cout << "���� �������" << endl;
}
void TestMersBlbio_CE_HT() { // ������ �� ����� ����� ������ � ����� � �� �������� ������
    ofstream out;       // ������ ��� ������
    out.open("MersBlbio_CE_HT.txt");
    int z = 0;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[6 * 1]{ 0.0 };
    int* thrs = new int[6]{ 1, 2, 3, 4, 6, 8 };
    //int n = 100;
    string file = "E:\\Progi\\Graph\\bio-CE-HT.txt";

    for (i = 0; i < 6; i++) {
        double time = TestTreeMersBlFile(file, z, thrs[i]);
        ptr[i] = time;
    }

    for (j = 0; j < 6; j++)
        out << ptr[j] << ' '; // ���������� ������� � �����
    out << '\n';
    cout << "���� �������" << endl;
}
void TestMersBetp2p_Gnutella08() { // ������ �� ����� ����� ������ � ����� � �� �������� ������
    ofstream out;       // ������ ��� ������
    out.open("MersBetp2p_Gnutella08.txt");
    int z = 1;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[6 * 1]{ 0.0 };
    int* thrs = new int[6]{ 1, 2, 3, 4, 6, 8 };
    //int n = 100;
    string file = "E:\\Progi\\Graph\\p2p-Gnutella08.txt";

    for (i = 0; i < 6; i++) {
        double time = TestTreeMersBetFile(file, z, thrs[i]);
        ptr[i] = time;
    }

    for (j = 0; j < 6; j++)
        out << ptr[j] << ' '; // ���������� ������� � �����
    out << '\n';
    cout << "���� �������" << endl;
}
void TestMersBlp2p_Gnutella08() { // ������ �� ����� ����� ������ � ����� � �� �������� ������
    ofstream out;       // ������ ��� ������
    out.open("MersBlp2p_Gnutella08.txt");
    int z = 1;
    double *ptr; // ������ �������
    int i, j;
    ptr = new double[6 * 1]{ 0.0 };
    int* thrs = new int[6]{ 1, 2, 3, 4, 6, 8 };
    //int n = 100;
    string file = "E:\\Progi\\Graph\\p2p-Gnutella08.txt";

    for (i = 0; i < 6; i++) {
        double time = TestTreeMersBlFile(file, z, thrs[i]);
        ptr[i] = time;
    }

    for (j = 0; j < 6; j++)
        out << ptr[j] << ' '; // ���������� ������� � �����
    out << '\n';
    cout << "���� �������" << endl;
}