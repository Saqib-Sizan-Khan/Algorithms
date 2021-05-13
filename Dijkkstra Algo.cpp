#include<iostream>
#include<vector>

using namespace std;

class Graph
{
public:
    int V;
    vector<int> *adj;
    vector<int> *weight;
    vector<int> visited;
    vector<int> not_visited;

    int* distance;
    int* parent;

    Graph(int vertices);
    void addEdge(int v1, int v2, int w);
    void dijkstra(int s);
    void bellman_ford(int s);
};

Graph::Graph(int vertices)
{
    V = vertices;
    adj = new vector<int>[vertices];
    weight = new vector<int>[vertices];

    for(int i=0; i<vertices; i++)
    {
        not_visited.push_back(i);
    }

    distance = new int[vertices];
    parent = new int[vertices];

    for(int i=0; i<vertices; i++)
    {
        distance[i] = 99999;
        parent[i] = -1;
    }
}

void Graph::addEdge(int v1, int v2, int w)
{
    adj[v1].push_back(v2);
    weight[v1].push_back(w);
}

void Graph::dijkstra(int s)
{
    while(!not_visited.empty())
    {
        int temp = 999999, index = -1;

        for(int i = 0; i<not_visited.size(); i++)
        {
            if(temp>distance[not_visited.at(i)])
            {
                temp = distance[not_visited.at(i)];
                index = i;
            }

        }

        visited.push_back(not_visited.at(index));


        int visiting_item = not_visited.at(index);

        not_visited.erase(not_visited.begin() + index);

        for(int i=0; i<adj[visiting_item].size(); i++)
        {
            int v = adj[visiting_item].at(i);

            if(distance[v] > distance[visiting_item] + weight[visiting_item].at(i))
            {
                distance[v] = distance[visiting_item] + weight[visiting_item].at(i);
                parent[v] = visiting_item;
            }
        }
    }

    cout<<distance[3]<<"\n";

    cout<<"\nShortest Path\n";

    for(int i=V-1; i>=0; i--)
    {
        cout<<visited[i]<<" -> ";
    }
    cout<<"\n";
}

void Graph::bellman_ford(int s)
{
    int k=1;

    while(k < V)
    {
        int i=0;
        while(i < V)
        {
            for(int j=0; j<adj[i].size(); j++)
            {
                int u = i;
                int v = adj[i].at(j);
                int w = weight[i].at(j);


                if(distance[v] > distance[u]+w)
                {
                    distance[v] = distance[u]+w;
                    parent[v] = u;
                }
            }
            i++;
        }
        k++;
    }

    cout<<"Distance\n";

    for(int i=0; i<V; i++)
    {
        cout<<i<<" Vertex Distance "<<distance[i]<<"\n";
    }

    cout<<"\nParents\n";

    for(int i=0; i<V; i++)
    {
        cout<<i<<" Vertex Parent "<<parent[i]<<"\n";
    }

    cout<<"\nShortest Path\n";

    for(int i=V-1; i>=0; i--)
    {
        cout<<visited[i]<<" -> ";
    }
}


int main()
{
    Graph g(4);

    g.addEdge(0,2,3);
    g.addEdge(0,1,5);
    g.addEdge(2,1,1);
    g.addEdge(1,3,2);

    g.distance[0] = 0;
    //g.dijkstra(0);
    g.bellman_ford(0);
}
