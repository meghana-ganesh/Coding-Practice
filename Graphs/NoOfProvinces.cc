//TC:O(V) where V is no. of vertices
class Solution {
public:
    void dfs(vector<vector<int>> &adj,int V,vector<int> &vis,int node)
    {
        vis[node] = 1;
        for (int neighbor = 0; neighbor < V; neighbor++) 
        {
            if (adj[node][neighbor] == 1 && !vis[neighbor]) {
                dfs(adj, V, vis, neighbor);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V,0);
        int count = 0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(adj,V,vis,i);
                count++;
            }
        }
        return count;
    }
};
