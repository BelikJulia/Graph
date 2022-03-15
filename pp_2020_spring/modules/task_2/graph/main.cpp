#include "./Graph.h"
#include "./Tests.h"
#include <gtest/gtest.h>
#include <omp.h>
#include <vector>
#include <iostream>

using namespace std;

/*void TestCreateRandomOr();
void TestCreateRandomNotOr();
void TestComponentCountOr();
void TestComponentCountNotOr();
void TestCin();
void TestFloyd();
void TestADijkstra();*/

/*int main()
{
    //TestCin();
    //TestCreateRandomOr();
    //TestCreateRandomNotOr();
    //TestComponentCountOr();
    //TestComponentCountNotOr();
    //TestFloyd();
    TestADijkstra();

    system("pause");
    return 0;
}

void TestCreateRandomOr()
{
    cout << "TestCreateRandomOr" << endl;
    Graph gr = Graph(5, true);
    cout << gr;
    cout << "Test Passed" << endl << endl;
}

void TestCreateRandomNotOr()
{
    cout << "TestCreateRandomNotOr" << endl;
    Graph gr = Graph(5, false);
    cout << gr;
    cout << "Test Passed" << endl << endl;
}

void TestComponentCountOr()
{
    cout << "TestComponentCountOr" << endl;
    Graph gr = Graph(6, true);
    cout << gr << endl;
    cout << gr.ComponentQuantity() << endl;
    cout << "Test Passed" << endl << endl;
}

void TestComponentCountNotOr()
{
    cout << "TestComponentCountOr" << endl;
    Graph gr = Graph(6, false);
    cout << gr << endl;
    cout << gr.ComponentQuantity() << endl;
    cout << "Test Passed" << endl << endl;
}
void TestCin()
{
    cout << "TestCin" << endl;
    Graph gr;
    cin >> gr;
    cout << gr << endl;
    cout << gr.ComponentQuantity() << endl;
    cout << "Test Passed" << endl << endl;
}

void TestFloyd()
{
    cout << "TestFloyd" << endl << "n = ";
    int n = 6;
    clock_t start, end;
    cin >> n;
    Graph gr = Graph(n, true);
    cout << gr;
    start = clock();
    int* fl = gr.Floyd();
    end = clock();
    float allTime = (float)(end - start) / CLOCKS_PER_SEC;
    for (int i = 0; i < n * n; i++)
    {
        if (i % n == 0)
            cout << endl;
        cout << fl[i] << " ";
    }
    cout << endl;
    cout << "time = " << allTime << endl;
    cout << "Test Passed" << endl << endl;
}
void TestADijkstra()
{
    cout << "TestADijkstra" << endl << "n = ";
    clock_t start, end;
    int n = 6;
    cin >> n;
    Graph gr = Graph(n, true);
    //cout << gr << endl;
    int* up = new int[n];
    double* dist = new double[n];
    int* up1 = new int[n];
    double* dist1 = new double[n];
    float allTime = 0;
    float allTime1 = 0;
    //for (int i = 0; i < n; i++)
    //{
        start = clock();
        gr.ADijkstraOMP(up, dist, 0, 4);
        //gr.ADijkstra(up, dist, 0);
        end = clock();
        allTime += (float)(end - start) / CLOCKS_PER_SEC;
        start = clock();
        gr.ADijkstra(up1, dist1, 0);
        end = clock();
        allTime1 += (float)(end - start) / CLOCKS_PER_SEC;
        
        for (int i = 0; i < n; i++)
        {
            //cout << dist[i] << " ";
            if (dist[i] != dist1[i])
                cout << "!";
        }
        cout << endl;
    //}
    cout << "time par = " << allTime << endl;
    cout << "time seq = " << allTime1 << endl;
    cout << "Test Passed" << endl << endl;
}*/
/*TEST(Graph_Test, Test_Time_1000) {
    const int n = 1000;
    Graph gr = Graph(n, true);
    const int thr = 1;
    int* up = new int[n];
    double* dist = new double[n];
    int* up2 = new int[n];
    double* dist2 = new double[n];
    int* up3 = new int[n];
    double* dist3 = new double[n];
    int* up4 = new int[n];
    double* dist4 = new double[n];
    double start, end, start2, end2, start3, end3, start4, end4;

    start = omp_get_wtime();
    gr.ADijkstra(up, dist, 0);
    end = omp_get_wtime();

    start2 = omp_get_wtime();
    gr.ADijkstraOMP(up2, dist2, 0, 2);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    gr.ADijkstraOMP(up3, dist3, 0, 3);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    gr.ADijkstraOMP(up4, dist4, 0, 4);
    end4 = omp_get_wtime();

    std::cout << std::endl;

    std::cout << "seq " << end - start << std::endl << "par 2 " << end2 - start2 << std::endl;
    std::cout << "par 3 " << end3 - start3 << std::endl << "par 4 " << end4 - start4 << std::endl;
    std::cout << "boost 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost 4 " << (end - start) / (end4 - start4) << std::endl << std::endl;

    for (int i = 0; i < n; i++) {
        if (dist[i] != dist4[i])
            std::cout << "!";
    }
    delete[] up;
    delete[] dist;
    delete[] up2;
    delete[] dist2;
    delete[] up3;
    delete[] dist3;
    delete[] up4;
    delete[] dist4;
    std::cout << std::endl;

    ASSERT_EQ(1, 1);
}

TEST(Graph_Test, Test_Time_5000) {
    const int n = 5000;
    Graph gr = Graph(n, true);
    const int thr = 1;
    int* up = new int[n];
    double* dist = new double[n];
    int* up2 = new int[n];
    double* dist2 = new double[n];
    int* up3 = new int[n];
    double* dist3 = new double[n];
    int* up4 = new int[n];
    double* dist4 = new double[n];
    double start, end, start2, end2, start3, end3, start4, end4;

    start = omp_get_wtime();
    gr.ADijkstra(up, dist, 0);
    end = omp_get_wtime();

    start2 = omp_get_wtime();
    gr.ADijkstraOMP(up2, dist2, 0, 2);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    gr.ADijkstraOMP(up3, dist3, 0, 3);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    gr.ADijkstraOMP(up4, dist4, 0, 4);
    end4 = omp_get_wtime();

    std::cout << std::endl;

    std::cout << "seq " << end - start << std::endl << "par 2 " << end2 - start2 << std::endl;
    std::cout << "par 3 " << end3 - start3 << std::endl << "par 4 " << end4 - start4 << std::endl;
    std::cout << "boost 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost 4 " << (end - start) / (end4 - start4) << std::endl << std::endl;

    for (int i = 0; i < n; i++) {
        if (dist[i] != dist4[i])
            std::cout << "!";
    }
    delete[] up;
    delete[] dist;
    delete[] up2;
    delete[] dist2;
    delete[] up3;
    delete[] dist3;
    delete[] up4;
    delete[] dist4;
    std::cout << std::endl;

    ASSERT_EQ(1, 1);
}

TEST(Graph_Test, Test_Time_10000) {
    const int n = 10000;
    Graph gr = Graph(n, true);
    const int thr = 1;
    int* up = new int[n];
    double* dist = new double[n];
    int* up2 = new int[n];
    double* dist2 = new double[n];
    int* up3 = new int[n];
    double* dist3 = new double[n];
    int* up4 = new int[n];
    double* dist4 = new double[n];
    double start, end, start2, end2, start3, end3, start4, end4;

    start = omp_get_wtime();
    gr.ADijkstra(up, dist, 0);
    end = omp_get_wtime();

    start2 = omp_get_wtime();
    gr.ADijkstraOMP(up2, dist2, 0, 2);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    gr.ADijkstraOMP(up3, dist3, 0, 3);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    gr.ADijkstraOMP(up4, dist4, 0, 4);
    end4 = omp_get_wtime();

    std::cout << std::endl;

    std::cout << "seq " << end - start << std::endl << "par 2 " << end2 - start2 << std::endl;
    std::cout << "par 3 " << end3 - start3 << std::endl << "par 4 " << end4 - start4 << std::endl;
    std::cout << "boost 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost 4 " << (end - start) / (end4 - start4) << std::endl << std::endl;

    for (int i = 0; i < n; i++) {
        if (dist[i] != dist4[i])
            std::cout << "!";
    }
    delete[] up;
    delete[] dist;
    delete[] up2;
    delete[] dist2;
    delete[] up3;
    delete[] dist3;
    delete[] up4;
    delete[] dist4;
    std::cout << std::endl;

    ASSERT_EQ(1, 1);
}*/

/*TEST(Graph_Test, Test_Time_100) {
    int n = 100;
    int m = 2 * n;
    Graph gr = Graph(n, m);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n);
    m += n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;

    start = omp_get_wtime();
    vert1 = gr.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n);
    m += n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n);
    m += n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n);
    m += n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n);
    m += n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

       
    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_Time_Full) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateFull(n);
    Graph gr2 = Graph();
    gr2.CreateFull(n * 2);
    Graph gr3 = Graph();
    gr3.CreateFull(n * 4);
    Graph gr4 = Graph();
    gr4.CreateFull(n * 8);
    Graph gr5 = Graph();
    gr5.CreateFull(n * 16);
    Graph gr6 = Graph();
    gr6.CreateFull(n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/
/*TEST(Graph_Test, Test_Time_FullBi) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateFullBi(n); 

    Graph gr2 = Graph();
    gr2.CreateFullBi(n * 2);
    Graph gr3 = Graph();
    gr3.CreateFullBi(n * 4);
    Graph gr4 = Graph();
    gr4.CreateFullBi(n * 8);
    Graph gr5 = Graph();
    gr5.CreateFullBi(n * 16);
    Graph gr6 = Graph();
    gr6.CreateFullBi(n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << gr1.GetM() << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << " m = " << gr2.GetM() << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << " m = " << gr3.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << " m = " << gr4.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << " m = " << gr5.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << " m = " << gr6.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_Time_Bi) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateBi(n);
    Graph gr2 = Graph();
    gr2.CreateBi(n * 2);
    Graph gr3 = Graph();
    gr3.CreateBi(n * 4);
    Graph gr4 = Graph();
    gr4.CreateBi(n * 8);
    Graph gr5 = Graph();
    gr5.CreateBi(n * 16);
    Graph gr6 = Graph();
    gr6.CreateBi(n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << gr1.GetM() << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << " m = " << gr2.GetM() << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << " m = " << gr3.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << " m = " << gr4.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << " m = " << gr5.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << " m = " << gr6.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_Time_Tree2) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateTree(2, n);
    Graph gr2 = Graph();
    gr2.CreateTree(2, n * 2);
    Graph gr3 = Graph();
    gr3.CreateTree(2, n * 4);
    Graph gr4 = Graph();
    gr4.CreateTree(2, n * 8);
    Graph gr5 = Graph();
    gr5.CreateTree(2, n * 16);
    Graph gr6 = Graph();
    gr6.CreateTree(2, n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << gr1.GetM() << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << " m = " << gr2.GetM() << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << " m = " << gr3.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << " m = " << gr4.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << " m = " << gr5.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << " m = " << gr6.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_Time_Tree3) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateTree(3, n);
    Graph gr2 = Graph();
    gr2.CreateTree(3, n * 2);
    Graph gr3 = Graph();
    gr3.CreateTree(3, n * 4);
    Graph gr4 = Graph();
    gr4.CreateTree(3, n * 8);
    Graph gr5 = Graph();
    gr5.CreateTree(3, n * 16);
    Graph gr6 = Graph();
    gr6.CreateTree(3, n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << gr1.GetM() << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << " m = " << gr2.GetM() << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << " m = " << gr3.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << " m = " << gr4.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << " m = " << gr5.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << " m = " << gr6.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_Time_Tree4){
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateTree(4, n);
    Graph gr2 = Graph();
    gr2.CreateTree(4, n * 2);
    Graph gr3 = Graph();
    gr3.CreateTree(4, n * 4);
    Graph gr4 = Graph();
    gr4.CreateTree(4, n * 8);
    Graph gr5 = Graph();
    gr5.CreateTree(4, n * 16);
    Graph gr6 = Graph();
    gr6.CreateTree(4, n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << gr1.GetM() << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << " m = " << gr2.GetM() << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << " m = " << gr3.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << " m = " << gr4.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << " m = " << gr5.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << " m = " << gr6.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_Time_Tree1) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateTree(1, n);
    Graph gr2 = Graph();
    gr2.CreateTree(1, n * 2);
    Graph gr3 = Graph();
    gr3.CreateTree(1, n * 4);
    Graph gr4 = Graph();
    gr4.CreateTree(1, n * 8);
    Graph gr5 = Graph();
    gr5.CreateTree(1, n * 16);
    Graph gr6 = Graph();
    gr6.CreateTree(1, n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << gr1.GetM() << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << " m = " << gr2.GetM() << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << " m = " << gr3.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << " m = " << gr4.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << " m = " << gr5.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << " m = " << gr6.GetM() << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBet();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBetF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBetOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBetOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBetOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBetOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBetOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_TimeBL_N1) {
    int n = 100;
    int m = 2 * n;
    Graph gr = Graph(n, m);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n);
    m += n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;

    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n);
    m += n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n);
    m += n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n);
    m += n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n);
    m += n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_TimeBL_N2) {
    int n = 100;
    int m = 2 * n;
    Graph gr = Graph(n, m);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 2);
    m += 2 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;

    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 2);
    m += 2 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 2);
    m += 2 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 2);
    m += 2 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 2);
    m += 2 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_TimeBL_N3) {
    int n = 100;
    int m = 2 * n;
    Graph gr = Graph(n, m);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 3);
    m += 3 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;

    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 3);
    m += 3 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 3);
    m += 3 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 3);
    m += 3 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 3);
    m += 3 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_TimeBL_N4) {
    int n = 100;
    int m = 2 * n;
    Graph gr = Graph(n, m);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 4);
    m += 4 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;

    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 4);
    m += 4 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 4);
    m += 4 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 4);
    m += 4 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    gr.AddN(n);
    gr.AddM(n * 4);
    m += 4 * n;
    n *= 2;
    std::cout << std::endl;
    std::cout << "n = " << n << " m = " << m << std::endl;
    start = omp_get_wtime();
    vert1 = gr.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_Time_Fullbl) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateFull(n);
    Graph gr2 = Graph();
    gr2.CreateFull(n * 2);
    Graph gr3 = Graph();
    gr3.CreateFull(n * 4);
    Graph gr4 = Graph();
    gr4.CreateFull(n * 8);
    Graph gr5 = Graph();
    gr5.CreateFull(n * 16);
    Graph gr6 = Graph();
    gr6.CreateFull(n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;

    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;


    ASSERT_EQ(0, 0);
}*/
/*TEST(Graph_Test, Test_Time_FullBibl) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateFullBi(n);

    Graph gr2 = Graph();
    gr2.CreateFullBi(n * 2);
    Graph gr3 = Graph();
    gr3.CreateFullBi(n * 4);
    Graph gr4 = Graph();
    gr4.CreateFullBi(n * 8);
    Graph gr5 = Graph();
    gr5.CreateFullBi(n * 16);
    Graph gr6 = Graph();
    gr6.CreateFullBi(n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;


    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_Time_Bibl) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateBi(n);
    Graph gr2 = Graph();
    gr2.CreateBi(n * 2);
    Graph gr3 = Graph();
    gr3.CreateBi(n * 4);
    Graph gr4 = Graph();
    gr4.CreateBi(n * 8);
    Graph gr5 = Graph();
    gr5.CreateBi(n * 16);
    Graph gr6 = Graph();
    gr6.CreateBi(n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;


    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    ASSERT_EQ(0, 0);
}*/
/*TEST(Graph_Test, Test_Time_Tree1bl) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateTree(1, n);
    Graph gr2 = Graph();
    gr2.CreateTree(1, n * 2);
    Graph gr3 = Graph();
    gr3.CreateTree(1, n * 4);
    Graph gr4 = Graph();
    gr4.CreateTree(1, n * 8);
    Graph gr5 = Graph();
    gr5.CreateTree(1, n * 16);
    Graph gr6 = Graph();
    gr6.CreateTree(1, n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;


    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_Time_Tree2) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateTree(2, n);
    Graph gr2 = Graph();
    gr2.CreateTree(2, n * 2);
    Graph gr3 = Graph();
    gr3.CreateTree(2, n * 4);
    Graph gr4 = Graph();
    gr4.CreateTree(2, n * 8);
    Graph gr5 = Graph();
    gr5.CreateTree(2, n * 16);
    Graph gr6 = Graph();
    gr6.CreateTree(2, n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;


    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, Test_Time_Tree3) {
    int n = 100;
    Graph gr1 = Graph();
    gr1.CreateTree(3, n);
    Graph gr2 = Graph();
    gr2.CreateTree(3, n * 2);
    Graph gr3 = Graph();
    gr3.CreateTree(3, n * 4);
    Graph gr4 = Graph();
    gr4.CreateTree(3, n * 8);
    Graph gr5 = Graph();
    gr5.CreateTree(3, n * 16);
    Graph gr6 = Graph();
    gr6.CreateTree(3, n * 32);
    const int thr1 = 2;
    const int thr2 = 3;
    const int thr3 = 4;
    const int thr4 = 5;
    const int thr5 = 8;
    double start, end, start1, end1, start2, end2, start3, end3, start4, end4, start5, end5, start6, end6, start7, end7;


    start = omp_get_wtime();
    vector<int> vert1 = gr1.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vector<int> vert = gr1.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vector<int> vert2 = gr1.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vector<int> vert3 = gr1.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vector<int> vert4 = gr1.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vector<int> vert5 = gr1.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vector<int> vert6 = gr1.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << std::endl;
    std::cout << "n = " << n << std::endl;
    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 2 << std::endl;

    start = omp_get_wtime();
    vert1 = gr2.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr2.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr2.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr2.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr2.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr2.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr2.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 4 << std::endl;
    start = omp_get_wtime();
    vert1 = gr3.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr3.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr3.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr3.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr3.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr3.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr3.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 8 << std::endl;
    start = omp_get_wtime();
    vert1 = gr4.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr4.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr4.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr4.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr4.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr4.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr4.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 16 << std::endl;
    start = omp_get_wtime();
    vert1 = gr5.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr5.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr5.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr5.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr5.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr5.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr5.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    std::cout << std::endl;
    std::cout << "n = " << n * 32 << std::endl;
    start = omp_get_wtime();
    vert1 = gr6.MersBl();
    end = omp_get_wtime();

    start1 = omp_get_wtime();
    vert = gr6.MersBlF();
    end1 = omp_get_wtime();

    start2 = omp_get_wtime();
    vert2 = gr6.MersBlOMP(thr1);
    end2 = omp_get_wtime();

    start3 = omp_get_wtime();
    vert3 = gr6.MersBlOMP(thr2);
    end3 = omp_get_wtime();

    start4 = omp_get_wtime();
    vert4 = gr6.MersBlOMP(thr3);
    end4 = omp_get_wtime();

    start5 = omp_get_wtime();
    vert5 = gr6.MersBlOMP(thr4);
    end5 = omp_get_wtime();

    start6 = omp_get_wtime();
    vert6 = gr6.MersBlOMP(thr5);
    end6 = omp_get_wtime();

    std::cout << "seq bet " << end - start << std::endl << "par bet 2 " << end2 - start2 << std::endl;
    std::cout << "par bet 3 " << end3 - start3 << std::endl << "par bet 4 " << end4 - start4 << std::endl;
    std::cout << "par bet 5 " << end5 - start5 << std::endl << "par bet 8 " << end6 - start6 << std::endl;
    std::cout << "F bet " << end1 - start1 << std::endl;
    std::cout << "boost bet 2 " << (end - start) / (end2 - start2) << std::endl;
    std::cout << "boost bet 3 " << (end - start) / (end3 - start3) << std::endl;
    std::cout << "boost bet 4 " << (end - start) / (end4 - start4) << std::endl;
    std::cout << "boost bet 5 " << (end - start) / (end5 - start5) << std::endl;
    std::cout << "boost bet 8 " << (end - start) / (end6 - start6) << std::endl;

    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, TestMersBetn){
    TestMersBetn();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBet2n) {
    TestMersBet2n();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBet3n) {
    TestMersBet3n();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBet4n) {
    TestMersBet4n();
    ASSERT_EQ(0, 0);
}

TEST(Graph_Test, TestMersBln) {
    TestMersBln();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBl2n) {
    TestMersBl2n();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBl3n) {
    TestMersBl3n();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBl4n) {
    TestMersBl4n();
    ASSERT_EQ(0, 0);
}

TEST(Graph_Test, TestMersBetFull) {
    TestMersBetFull();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBetFullBi) {
    TestMersBetFullBi();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBetBi) {
    TestMersBetBi();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBetTree1) {
    TestMersBetTree1();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBetTree2) {
    TestMersBetTree2();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBetTree3) {
    TestMersBetTree3();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBetTree4) {
    TestMersBetTree4();
    ASSERT_EQ(0, 0);
}*/

/*TEST(Graph_Test, TestMersBlFull) {
    TestMersBlFull();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBlFullBi) {
    TestMersBlFullBi();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBlBi) {
    TestMersBlBi();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBlTree1) {
    TestMersBlTree1();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBlTree2) {
    TestMersBlTree2();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBlTree3) {
    TestMersBlTree3();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBlTree4) {
    TestMersBlTree4();
    ASSERT_EQ(0, 0);
}*/
/*TEST(Graph_Test, TestMersBetbio_CE_GT) {
    TestMersBetbio_CE_GT();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBlbio_CE_GT) {
    TestMersBlbio_CE_GT();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBetbio_CE_HT) {
    TestMersBetbio_CE_HT();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBlbio_CE_HT) {
    TestMersBlbio_CE_HT();
    ASSERT_EQ(0, 0);
}*/
TEST(Graph_Test, TestMersBetp2p_Gnutella08) {
    TestMersBetp2p_Gnutella08();
    ASSERT_EQ(0, 0);
}
TEST(Graph_Test, TestMersBlp2p_Gnutella08) {
    TestMersBlp2p_Gnutella08();
    ASSERT_EQ(0, 0);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
