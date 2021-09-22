#include<bits/stdc++.h>
using namespace std;
#define V 6

vector<int> topological_sort(vector<int>graph[])
{
    vector<int>result;
    queue<int>q;
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<graph[i].size();j++)
            indegree[graph[i][j]]++;
    }
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        result.push_back(v);
        for(auto i=graph[v].begin();i!=graph[v].end();i++)
        {
            indegree[*i]--;
            if(indegree[*i]==0)
                q.push(*i);
        }
    }
    if(result.size()!=V)
    {
        cout<<"Topological Not possible ";
        exit(0);
    }
   return result;
}

void addEdge(vector<int>graph[],int u,int v)
{
    graph[u].emplace_back(v);
}

int main()
{
    vector<int>graph[V];
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,1,3);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    vector<int>res=topological_sort(graph);
    for(int i=0;i<V;i++)
        cout<<res[i]<<" ";
    return 0;
}