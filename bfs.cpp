#include<bits/stdc++.h>
using namespace std;
#define V 9

void addEdge(vector<int>graph[],int u,int v)
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
} 

void bfs(vector<int>graph[],int start)
{
    vector<bool>visited(V,false);
    queue<int>q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto i=graph[temp].begin();i!=graph[temp].end();i++)
        {
            if(!visited[*i])
            {
                q.push(*i);
                visited[*i]=true;
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
          
            cout<<i<<" ";
        }
    }
}

int main()
{
    vector<int>graph[V];
    addEdge(graph,0,1);
    addEdge(graph,0,3);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,2,6);
    addEdge(graph,3,4);
    addEdge(graph,4,5);
    addEdge(graph,5,6);
    addEdge(graph,7,8);
    cout<<"BFS traversal from 0: "<<endl;
    bfs(graph,0);
    return 0;
}