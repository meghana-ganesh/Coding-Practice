//TC:O(N+2E)
//SC:O(N) - QUEUE + O(N) - VISITED ARRAY
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool bfs(int V,vector<int> adj[],vector<int> &vis,int start)
    {
        queue<pair<int,int>> q;
        q.push({start,-1});
        vis[start] = 1;
        while(!q.empty())
        {
            int cur = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int i=0;i<adj[cur].size();i++)
            {
                int neighbour = adj[cur][i];
                if(!vis[neighbour])
                {
                    vis[neighbour] = 1;
                    q.push({neighbour,cur});
                }
                else if(parent != neighbour)
                {
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(bfs(V,adj,vis,i))
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
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
