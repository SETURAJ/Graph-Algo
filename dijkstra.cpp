#include<bits/stdc++.h>
using namespace std;
#define V 9

vector<int> dijkstra(vector<pair<int,int>> graph[],int start)
{
    vector<int>dist(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>>pq;
    pq.push(make_pair(start,0));
    dist[start]=0;
    while(!pq.empty())
    {
        int u=pq.top().first;
        pq.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i].first;
            int w=graph[u][i].second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                pq.push(make_pair(v,dist[v]));
            }
        }
    }
    return dist;
}

void addEdge(vector<pair<int,int>> graph[],int u,int v,int w)
{
    graph[u].emplace_back(make_pair(v,w));
    graph[v].emplace_back(make_pair(u,w));
}

int main()
{
    vector<pair<int,int>>graph[V];
    addEdge(graph,0,1,4);
    addEdge(graph,0,7,8);
    addEdge(graph,1,7,11);
    addEdge(graph,1,2,8);
    addEdge(graph,2,8,2);
    addEdge(graph,2,5,4);
    addEdge(graph,2,3,7);
    addEdge(graph,3,4,9);
    addEdge(graph,3,5,14);
    addEdge(graph,4,5,10);
    addEdge(graph,5,6,2);
    addEdge(graph,6,7,1);
    addEdge(graph,6,8,6);
    addEdge(graph,7,8,7);

    vector<int> dist=dijkstra(graph,1);
    for(int i=0;i<V;i++)
        cout<<i<<"\t"<<dist[i]<<endl;

    return 0;
}