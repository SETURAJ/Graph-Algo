#include<bits/stdc++.h>
using namespace std;
#define V 8

int bfs(int source,int dest,vector<int>&parent,vector<vector<int>>&residualgraph)
{
    fill(parent.begin(),parent.end(),-1);
    parent[source]=-2;
    queue<pair<int,int>>q;
    q.push({source,INT_MAX});
    while(!q.empty())
    {
        int u=q.front().first;
        int capacity=q.front().second;
        q.pop();
        for(int av=0;av<V;av++)
        {
            if(u!=av && parent[av]==-1 && residualgraph[u][av]!=0)
            {
                parent[av]=u;
                int min_cap=min(capacity,residualgraph[u][av]);
                if(av==dest)
                    return min_cap;
                q.push({av,min_cap});   
            }
        }
    }
    return 0;
}

int ford_fulkerson(vector<vector<int>>&graph,int source,int dest)
{
    vector<int>parent(V,-1);
    vector<vector<int>>residualgraph=graph;
    int min_cap=0,max_flow=0;
    while(min_cap=bfs(source,dest,parent,residualgraph))
    {
        max_flow+=min_cap;
        int u=dest;
        while(u!=source)
        {
            int v=parent[u];
            residualgraph[u][v]+=min_cap;
            residualgraph[v][u]-=min_cap;
            u=v;
        }
    }
    return max_flow;
}

void addEdge(vector<vector<int>>&graph,int u,int v,int w)
{
   graph[u][v]=w;
}

int main()
{
    vector<vector<int>>graph(V,vector<int>(V));
    addEdge(graph,0,1,8);
    addEdge(graph,0,2,7);
    addEdge(graph,0,3,4);
    addEdge(graph,1,4,3);
    addEdge(graph,1,5,9);
    addEdge(graph,1,2,2);
    addEdge(graph,2,3,5);
    addEdge(graph,2,5,6);
    addEdge(graph,3,6,2);
    addEdge(graph,3,5,7);
    addEdge(graph,4,7,9);
    addEdge(graph,5,4,3);
    addEdge(graph,5,7,5);
    addEdge(graph,5,6,4);
    addEdge(graph,6,7,8);


    cout<<ford_fulkerson(graph,0,7);//source,dest
    return 0;
}