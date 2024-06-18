//TC:O(N)+O(2E) (2E is TC for traversal of all neighbours of a node i.e degree of a node)
//SC:O(3N) which is almost equal to O(N)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution
{
    public:
    vector<int> bfs(int V,vector<vector<int>> adj)
    {
        vector<int> bfs;
        vector<int> vis(V,0);
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            bfs.push_back(cur);
            for(int i=0;i<adj[cur].size();i++)
            {
                int neighbour = adj[cur][i];
                if(!vis[neighbour])
                {
                    vis[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }
        return bfs;
    }
};
int main()
{
    int V,E;
    cout << "enter the no. of vertices & edges:";
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for(int i = 0;i<E;i++)
    {
        int u,v;
        cout << "enter edge u v:";
        cin >> u >> v;    
        adj[u].push_back(v);
        adj[v].push_back(u);    
    }
    Solution s;
    vector<int> res = s.bfs(V,adj);
    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << " ";
    }
}
