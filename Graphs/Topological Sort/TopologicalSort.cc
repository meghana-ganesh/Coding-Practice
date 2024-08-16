//TC:O(V+E)
//SC:O(V+E)
class Solution
{
	public:
	void dfs(int V,vector<int> adj[],vector<int> &vis,int start,vector<int> &st)
	{
	    vis[start] = 1;
	    for(int i=0;i<adj[start].size();i++)
	    {
	        int neighbour = adj[start][i];
	        if(!vis[neighbour])
	        {
	            dfs(V,adj,vis,neighbour,st);
	        }
	    }
	    st.push_back(start);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
	    vector<int> st;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	            dfs(V,adj,vis,i,st);
	    }
	    reverse(st.begin(),st.end());
	    return st;
	}
};
