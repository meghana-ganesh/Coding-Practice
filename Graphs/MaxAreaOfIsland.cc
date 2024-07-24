class Solution {
public:
    void dfs(vector<vector<int>> &grid,int row,int col,vector<int> &deltaRow,vector<int> &deltaCol,int n,int m,int &maxarea)
    {
        grid[row][col] = -1;
        for(int i=0;i<4;i++)
        {
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1)
            {
                grid[nrow][ncol] = -1;
                maxarea++;
                dfs(grid,nrow,ncol,deltaRow,deltaCol,n,m,maxarea);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        vector<int> deltaRow = {-1,0,+1,0};
        vector<int> deltaCol = {0,-1,0,+1};
        int n = grid.size();
        int m = grid[0].size();
        int maxAns = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    int maxarea = 1;
                    dfs(grid,i,j,deltaRow,deltaCol,n,m,maxarea);
                    maxAns = max(maxAns,maxarea);
                }
            }
        }
        return maxAns;
    }
};
