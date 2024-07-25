//TC:O(P*N) P - total no. of paths from source to target N - no. of nodes in the graph
class Solution {
public:
    void dfs(vector<vector<int>> &graph,int node,vector<int> &dfs_arr,int target,vector<vector<int>> &ans)
    {
        dfs_arr.push_back(node);
        if(node == target)
        {
            ans.push_back(dfs_arr);
        }
        else
        {
            for(int i=0;i<graph[node].size();i++)
            {
                int neighbour = graph[node][i];
                dfs(graph,neighbour,dfs_arr,target,ans);
            }
        }
        dfs_arr.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> ans;
        vector<int> dfs_arr;
        int target = graph.size() - 1;
        dfs(graph,0,dfs_arr,target,ans);
        return ans;
    }
};
