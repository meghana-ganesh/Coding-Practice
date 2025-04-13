//TC:O(V+E)
//SC:O(V) - recursion stack + O(V) - vis + adj list - O(V+E)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(vector<vector<int>> &adj,vector<int> &vis,int node,int parent)
    {
        vis[node] = 1;
        for(int i=0;i<adj[node].size();i++)
        {
            int neighbor = adj[node][i];
            if(!vis[neighbor])
            {
                if(dfs(adj,vis,neighbor,node))
                    return true;
            }
            else if(neighbor != parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        // Code here
        vector<int> vis(V);
        vector<vector<int>> adj(V);
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int parent = -1;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,vis,i,parent))
                    return true;
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
