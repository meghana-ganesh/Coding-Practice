//TC:O(N)+O(2E)
//SC:O(N)+O(N)+O(N) = O(N)

#include<iostream>
#include<vector>
using namespace std;

void dfs(int V,vector<vector<int>> adj,vector<int> &vis,vector<int> &ls,int node)
{
    vis[node] = 1;
    ls.push_back(node);
    for(int i=0;i<adj[node].size();i++)
    {
        int neighbour = adj[node][i];
        if(!vis[neighbour])
        {
            dfs(V,adj,vis,ls,neighbour);
        }
    }
}
int main()
{
    int V,E;
    vector<vector<int>> adj(V);
    cout << "enter the no. of vertices & edges:";
    cin >> V >> E;
    for(int i=0;i<E;i++)
    {
        int u,v;
        cout << "enter the edge u v:";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ls;
    vector<int> vis(V,0);
    dfs(V,adj,vis,ls,0);
    for(int i=0;i<ls.size();i++)
    {
        cout << ls[i] << " ";
    }
}
