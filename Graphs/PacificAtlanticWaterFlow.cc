//TC:O(N*M)
//SC:O(N*M) - recursive call stack
class Solution {
public:
    void dfs(vector<vector<int>>& heights,vector<vector<bool>> &ocean,int row,int col,vector<int> &deltaRow,vector<int> &deltaCol,int n,int m)
    {
        ocean[row][col] = true;
        for(int i=0;i<4;i++)
        {
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];
            if(nrow >=0 && ncol >= 0 && nrow < n && ncol < m && !ocean[nrow][ncol] && heights[nrow][ncol] >= heights[row][col])
            {
                dfs(heights,ocean,nrow,ncol,deltaRow,deltaCol,n,m);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<int> deltaRow = {-1,0,+1,0};
        vector<int> deltaCol = {0,-1,0,+1};
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            dfs(heights,pacific,i,0,deltaRow,deltaCol,n,m);
            dfs(heights,atlantic,i,m-1,deltaRow,deltaCol,n,m);
        }
        for(int j=0;j<m;j++)
        {
            dfs(heights,pacific,0,j,deltaRow,deltaCol,n,m);
            dfs(heights,atlantic,n-1,j,deltaRow,deltaCol,n,m);
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
