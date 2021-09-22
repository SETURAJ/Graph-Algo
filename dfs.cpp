#include<bits/stdc++.h>
using namespace std;
#define V 9

void addEdge(vector<int>graph[],int u,int v)
{
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
}

void dfs(vector<int>graph[],int start)
{
    vector<bool>visited(V,false);
    stack<int>s;
    s.push(start);
    visited[start]=true;
    while(!s.empty())
    {
        int temp=s.top();
        s.pop();
        cout<<temp<<" ";
        for(auto i=graph[temp].begin();i!=graph[temp].end();i++)
        {
            if(!visited[*i])
            {
                s.push(*i);
                visited[*i]=true;
            }
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
    cout<<"DFS Traversal:"<<endl;
    dfs(graph,0);
    return 0;
}