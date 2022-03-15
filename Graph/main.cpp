#include "Graph.h"
#include "Tests.h"
#include <vector>
#include <fstream>
#include <iostream>

#include <iomanip>
#include <ctime>

using namespace std;

//void TestCreateRandomOr();
//void TestCreateRandomNotOr();
//void TestComponentCountOr();
//void TestComponentCountNotOr();
//void TestCin();
//void TestFloyd();
//void TestADijkstra();
//void TestMera1();
//void TestMera2();
//void TestMeraAF();
//void TestMeraBlAF();
//void TestMeraDeg();
//void TestMeras();
//void TestMerasOMP();
//void TestFile();
//void TestDoub();
//void TestCreate();
//
//void Text();

int main() {
    TestMersBetbio_CE_GT();
    TestMersBlbio_CE_GT();
    TestMersBetbio_CE_HT();
    TestMersBlbio_CE_HT();
    TestMersBetp2p_Gnutella08();
    TestMersBlp2p_Gnutella08();
    system("pause");
    return 0;
}

//void Text() {
//        ofstream out;       // объект для записи
//        out.open("spisok.txt"); // любой текстовый файл в твоём проекте
//        srand((unsigned)time(NULL));
//        int *ptr; // создаём матрицу
//        int i, j;
//        ptr = new int[100];
//               
//        for (i = 0; i < 10; i++) {
//            for (j = 0; j < 10; j++)
//                out << ptr[i * 10 + j] << ' '; // записываем матрицу в поток
//            out << '\n';
//
//        }
//        cout << "Файл записан" << endl;
//}
//
//
//
//
//void TestCreateRandomOr()
//{
//    cout << "TestCreateRandomOr" << endl;
//    Graph gr = Graph(5, true);
//    cout << gr;
//    cout << "Test Passed" << endl << endl;
//}
//
//void TestCreateRandomNotOr()
//{
//    cout << "TestCreateRandomNotOr" << endl;
//    Graph gr = Graph(5, false);
//    cout << gr;
//    cout << "Test Passed" << endl << endl;
//}
//
//void TestComponentCountOr()
//{
//    cout << "TestComponentCountOr" << endl;
//    Graph gr = Graph(6, true);
//    cout << gr << endl;
//    cout << gr.ComponentQuantity() << endl;
//    cout << "Test Passed" << endl << endl;
//}
//
//void TestComponentCountNotOr()
//{
//    cout << "TestComponentCountOr" << endl;
//    Graph gr = Graph(6, false);
//    cout << gr << endl;
//    cout << gr.ComponentQuantity() << endl;
//    cout << "Test Passed" << endl << endl;
//}
//void TestCin()
//{
//    cout << "TestCin" << endl;
//    Graph gr;
//    cin >> gr;
//    cout << gr << endl;
//    cout << gr.ComponentQuantity() << endl;
//    cout << "Test Passed" << endl << endl;
//}
//
//void TestFloyd()
//{
//    cout << "TestFloyd" << endl << "n = ";
//    int n = 6;
//    clock_t start, end;
//    cin >> n;
//    Graph gr = Graph(n, true);
//    cout << gr;
//    start = clock();
//    double* fl = gr.Floyd();
//    end = clock();
//    float allTime = (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < n * n; i++)
//    {
//        if (i % n == 0)
//            cout << endl;
//        cout << fl[i] << " ";
//    }
//    cout << endl;
//    cout << "time = " << allTime << endl;
//    cout << "Test Passed" << endl << endl;
//}
//void TestADijkstra()
//{
//    cout << "TestADijkstra" << endl << "n = ";
//    clock_t start, end;
//    int n = 6;
//    cin >> n;
//    Graph gr = Graph(n, true);
//    int* up = new int[n];
//    double* dist = new double[n];
//    int* up1 = new int[n];
//    double* dist1 = new double[n];
//    float allTime = 0;
//    float allTime1 = 0;
//    start = clock();
//    gr.ADijkstraOMP(up, dist, 0, 4);
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    start = clock();
//    gr.ADijkstra(up1, dist1, 0);
//    end = clock();
//    allTime1 += (float)(end - start) / CLOCKS_PER_SEC;
//        
//    for (int i = 0; i < n; i++) {
//        if (dist[i] != dist1[i])
//            cout << "!";
//    }
//    cout << endl;
//    cout << "time par = " << allTime << endl;
//    cout << "time seq = " << allTime1 << endl;
//    cout << "boost = " << allTime1 / allTime << endl;
//    cout << "Test Passed" << endl << endl;
//}
//void TestMera1()
//{
//    cout << "TestMera1" << endl << "n = ";
//    clock_t start, end;
//    int n = 6;
//    cin >> n;
//    Graph gr = Graph(n, true);
//    float allTime = 0;
//    start = clock();
//    double mera = gr.MerBet(0);
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//
//    cout << /*endl << gr << endl << */"Mera = " << mera << endl;
//    cout << "time = " << allTime << endl;
//    cout << "Test Passed" << endl << endl;
//}
//void TestMera2()
//{
//    cout << "TestMera2" << endl << "n = ";
//    clock_t start, end;
//    int n = 6;
//    cin >> n;
//    Graph gr = Graph(n, true);
//    //cout << endl << gr << endl;
//    float allTime = 0;
//    start = clock();
//    double mera = gr.MerBetF(0); 
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//
//    cout << endl << gr << endl << "Mera = " << mera << endl;
//    cout << "time = " << allTime << endl;
//    cout << "Test Passed" << endl << endl;
//}
//
//void TestMeraAF() {
//    cout << "TestMeraAF" << endl << "n = ";
//    clock_t start, end;
//    int n = 6;
//    cin >> n;
//    Graph gr = Graph(n, true);
//    //cout << endl << gr << endl;
//    float allTime = 0;
//    start = clock();
//    double mera = gr.MerBet(0);
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    float allTime1 = 0;
//    start = clock();
//    double mera1 = gr.MerBetF(0);
//    end = clock();
//    allTime1 += (float)(end - start) / CLOCKS_PER_SEC;
//
//    cout <</* endl << gr << endl << */"Mera AD = " << mera << endl << "Mera F = " << mera1 << endl;
//    cout << "time AD = " << allTime << endl;
//    cout << "time F = " << allTime1 << endl;
//    cout << "Test Passed" << endl << endl;
//}
//
//void TestMeraBlAF() {
//    cout << "TestMeraBlAF" << endl << "n = ";
//    clock_t start, end;
//    int n = 6;
//    cin >> n;
//    Graph gr = Graph(n, true);
//    //cout << endl << gr << endl;
//    float allTime = 0;
//    start = clock();
//    double mera = gr.MerBl(0);
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    float allTime1 = 0;
//    start = clock();
//    double mera1 = gr.MerBlF(0);
//    end = clock();
//    allTime1 += (float)(end - start) / CLOCKS_PER_SEC;
//
//    cout <</* endl << gr << endl << */"Mera AD = " << mera << endl << "Mera F = " << mera1 << endl;
//    cout << "time AD = " << allTime << endl;
//    cout << "time F = " << allTime1 << endl;
//    cout << "Test Passed" << endl << endl;
//}
//
//void TestMeraDeg() {
//    cout << "TestMeraDeg" << endl << "n = ";
//    clock_t start, end;
//    int n = 6;
//    cin >> n;
//    Graph gr = Graph(n, true);
//    //cout << endl << gr << endl;
//    float allTime = 0;
//    start = clock();
//    double mera = gr.MerDeg(0);
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//
//    cout << /*endl << gr << endl << */"Mera = " << mera << endl;
//    cout << "time = " << allTime << endl;
//    cout << "Test Passed" << endl << endl;
//}
//void TestMeras() {
//    cout << "TestMeras" << endl << "n = ";
//    clock_t start, end;
//    int n = 6;
//    cin >> n;
//    Graph gr = Graph(n, true); 
//
//    float allTime = 0;
//    cout << endl << "MersBet" << endl;
//    start = clock();
//    vector<int> vert1 = gr.MersBet();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert1.size(); i++)
//        cout << vert1[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    allTime = 0;
//    cout << endl << "MersBetF" << endl;
//    start = clock();
//    vector<int> vert2 = gr.MersBetF();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert2.size(); i++)
//        cout << vert2[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    allTime = 0;
//    cout << endl << "MersBl" << endl;
//    start = clock();
//    vector<int> vert3 = gr.MersBl();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert3.size(); i++)
//        cout << vert3[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    allTime = 0;
//    cout << endl << "MersBlF" << endl;
//    start = clock();
//    vector<int> vert4 = gr.MersBlF();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert4.size(); i++)
//        cout << vert4[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    allTime = 0;
//    cout << endl << "MersDeg" << endl;
//    start = clock();
//    vector<int> vert5 = gr.MersDeg();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert5.size(); i++)
//        cout << vert5[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    cout << "Test Passed" << endl << endl;
//}
//
//void TestMerasOMP() {
//    cout << "TestMeras" << endl << "n = ";
//    clock_t start, end;
//    int n = 6;
//    int thr = 4;
//    cin >> n;
//    Graph gr = Graph(n, true);
//
//    float allTime = 0;
//    cout << endl << "MersBet" << endl;
//    start = clock();
//    vector<int> vert1 = gr.MersBet();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert1.size(); i++)
//        cout << vert1[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    allTime = 0;
//    cout << endl << "MersBetOMP" << endl;
//    start = clock();
//    vector<int> vert2 = gr.MersBetOMP(thr);
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert2.size(); i++)
//        cout << vert2[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    allTime = 0;
//    cout << endl << "MersBl" << endl;
//    start = clock();
//    vector<int> vert3 = gr.MersBl();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert3.size(); i++)
//        cout << vert3[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    allTime = 0;
//    cout << endl << "MersBlOMP" << endl;
//    start = clock();
//    vector<int> vert4 = gr.MersBlOMP(thr);
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert4.size(); i++)
//        cout << vert4[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    cout << "Test Passed" << endl << endl;
//}
//
//void TestFile() {
//    cout << "TestFile" << endl;
//    clock_t start, end;
//    //int n = 924;
//    //int m = 3239;
//    //string file = "E:\\Progi\\Graph\\bio-CE-GT.txt";
//    string file = "E:\\Progi\\Graph\\bio-CE-HT.txt";
//    Graph gr = Graph(file, 0);
//
//    float allTime = 0;
//    cout << endl << "MersBet" << endl;
//    start = clock();
//    vector<int> vert1 = gr.MersBet();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert1.size(); i++)
//        cout << vert1[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    allTime = 0;
//    cout << endl << "MersBetF" << endl;
//    start = clock();
//    vector<int> vert2 = gr.MersBetF();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert2.size(); i++)
//        cout << vert2[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    allTime = 0;
//    cout << endl << "MersBl" << endl;
//    start = clock();
//    vector<int> vert3 = gr.MersBl();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert3.size(); i++)
//        cout << vert3[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    allTime = 0;
//    cout << endl << "MersBlF" << endl;
//    start = clock();
//    vector<int> vert4 = gr.MersBlF();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert4.size(); i++)
//        cout << vert4[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    allTime = 0;
//    cout << endl << "MersDeg" << endl;
//    start = clock();
//    vector<int> vert5 = gr.MersDeg();
//    end = clock();
//    allTime += (float)(end - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < vert5.size(); i++)
//        cout << vert5[i] << " ";
//    cout << endl << "time = " << allTime << endl;
//
//    cout << "Test Passed" << endl << endl;
//}
//void TestDoub() {
//    cout << "TestDoub" << endl << "n = ";
//    int n = 6;
//    cin >> n;
//    Graph gr = Graph(n, true);
//    cout << gr << endl;
//    gr.AddN(n);
//    cout << "Add n vert " << endl << gr << endl;
//    gr.AddM(n * 3);
//    cout << "Add 3n ribs " << endl << gr << endl;
//    cout << "Test Passed" << endl;
//}
//
//void TestCreate() {
//    cout << "TestCreate" << endl << "n = ";
//    int n = 6;
//    cin >> n;
//    Graph gr1 = Graph();
//    gr1.CreateFull(n);
//    Graph gr2 = Graph();
//    gr2.CreateFullBi(n);
//    Graph gr3 = Graph();
//    gr3.CreateBi(n);
//    Graph gr4 = Graph();
//    gr4.CreateTree(3, n);
//    cout << "Full " << endl << gr1 << endl;
//    cout << "FullBi " << endl << gr2 << endl;
//    cout << "Bi" << endl << gr3 << endl;
//    cout << "Tree" << endl << gr4 << endl;
//    cout << "Test Passed" << endl;
//}
