#include "Graph.h"

Graph::Graph()
{
    n = 0;
}
Graph::Graph(int _n)
{
    n = _n;
    E = new int[n * n] { 0 };
}
Graph::Graph(int _n, int* _E)
{
    n = _n;
    E = new int[n * n];
    for (int i = 0; i < n * n; i++)
        E[i] = _E[i];
}
Graph::Graph(const Graph& tmp)
{
    n = tmp.n;
    E = new int[n * n];
    for (int i = 0; i < n * n; i++)
    {
        E[i] = tmp.E[i];
    }
}
Graph::~Graph()
{
    n = 0;
    delete[] E;
}
int Graph::GetN()
{
    return n;
}

void Graph::ADijkstra(const Graph& tmp, int* up, double* dist, int start)
{
    double sum = 0;
    PQueueElem<double, PQueueElem<double, int> > min;
    bool* vis = new bool[tmp.n * tmp.n];
    for (int i = 0; i < tmp.n * tmp.n; i++)
    {
        if (tmp.E[i] != 0)
        {
            sum += tmp.E[i];
            vis[i] = true;
        }
        else 
            vis[i] = false;
    }
    for (int i = 0; i < tmp.n; i++)
    {
        up[i] = -1;
        dist[i] = sum;
    }
    up[start] = 0;
    dist[start] = 0;
    PQueueElem<double, int>* DistNum = new PQueueElem<double, int>[tmp.n];
    for (int i = 0; i < tmp.n; i++)
    {
        DistNum[i].prior = dist[i];
        *DistNum[i].data = i;
    }
    PQueue<double, PQueueElem<double, int> > Dist(tmp.n, dist, DistNum);
    while (!Dist.IsEmpty())
    {
        min = Dist.Pop();
        for (int i = 0; i < tmp.n * tmp.n; i++)
        {
            if ((*min.data->data == i / tmp.n) && (vis[i]))
            {
                if (dist[*min.data->data] + tmp.E[i] < dist[i / tmp.n])
                {
                    dist[i / tmp.n] = dist[*min.data->data] + tmp.E[i];
                    up[i / tmp.n] = *min.data->data;
                }
                vis[i] = false;
            }
            else if ((*min.data->data == i % tmp.n) && (vis[i]))
            {
                if (dist[*min.data->data] + tmp.E[i] < dist[i % tmp.n])
                {
                    dist[i % tmp.n] = dist[*min.data->data] + tmp.E[i];
                    up[i % tmp.n] = *min.data->data;
                }
                vis[i] = false;
            }
        }
    }
}

int* Graph::GetComponents()
{
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = i;
    for (int i = 0; i < n; i++)//для неориентированного графа
    {
        for (int j = i + 1; j < n; j++)
        {
            if (E[i * n + j] > 0)
            {
                if (arr[i] < arr[j])
                    arr[j] = arr[i];
                else if (arr[i] > arr[j])
                    arr[i] = arr[j];
            }
        }
    }
    return arr;
}

int Graph::ComponentQuantity()
{
    int* arr = this->GetComponents();
    int comp = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == i)
            comp++;
    return comp;
}

int* Graph::Floyd()
{
    int* arr = new int[n * n];
    int sum = 0;
    for (int i = 0; i < n * n; i++)
        sum += E[i];
    for (int i = 0; i < n * n; i++)
    {
        if (E[i] == 0)
        {
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
            for (int j = 0; j < n; j++)
                if ((arr[i * n + k] + arr[k * n + j]) < arr[i * n + j])
                    arr[i * n + j] = arr[i * n + k] + arr[k * n + j];
    return arr;
}

