#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Graph
{
public:
    int V;
    vector<int> *adj;
    bool *visited;
    int *color;

    Graph(int V);
    void addEdge(int v1,int v2);
    void DFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];

    visited = new bool[V];

    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }

    color = new int[V];

    for(int i=0; i<V; i++)
    {
        color[i] = 1;
    }
}

void Graph::addEdge(int v1,int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

void Graph::DFS(int s)
{
    //cout<<s<<", ";
    visited[s] = true;

    for(int i=0; i<adj[s].size(); i++)
    {
        int v = adj[s].at(i);

        if(!visited[v])
        {
            if(color[s] == 1)
            {
                color[v] = 2;
            }
            else if(color[s] == 2)
            {
                color[v] = 1;
            }

            DFS(v);
        }
    }
}

int main()
{
    Graph g(4);

    g.addEdge(0,1);
    //g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(1,3);

    g.DFS(0);

    for(int i=0; i<4; i++)
    {
        //cout<<i<<": ";

        for(int j=0; j<g.adj[i].size(); j++)
        {
            int v = g.adj[i].at(j);

            if(g.color[i] == g.color[v])
            {
                cout<<"Not Bi-colorable\n";
                return 0;
            }

            //cout<<g.adj[i].at(j)<<", ";
        }
        //cout<<"\n";
    }

    cout<<"Bi-colorable\n";

    return 0;
}
