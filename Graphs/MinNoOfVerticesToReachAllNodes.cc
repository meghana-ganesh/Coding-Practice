//TC: O(N) + O(E)
//SC:O(N) - incoming array
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> incoming(n,0);
        vector<int> ans;
        for(int i=0;i<edges.size();i++)
        {
            incoming[edges[i][1]] += 1;
        }
        for(int i=0;i<n;i++)
        {
            if(incoming[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
