class Solution {
public:
    void bfs(vector<vector<int>> &grid,int row,int col,vector<int> &deltaRow,vector<int> &deltaCol,int n,int m)\
    {
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = -1;
        while(!q.empty())
        {
            auto [row,col] = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + deltaRow[i];
                int ncol = col + deltaCol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1)
                {
                    q.push({nrow,ncol});
                    grid[nrow][ncol] = -1;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        vector<int> deltaRow = {-1,0,+1,0};
        vector<int> deltaCol = {0,-1,0,+1};
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 1)
                bfs(grid,i,0,deltaRow,deltaCol,n,m);
            if(grid[i][m-1] == 1)
                bfs(grid,i,m-1,deltaRow,deltaCol,n,m);
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j] == 1)
                bfs(grid,0,j,deltaRow,deltaCol,n,m);
            if(grid[n-1][j] == 1)
                bfs(grid,n-1,j,deltaRow,deltaCol,n,m);
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};
