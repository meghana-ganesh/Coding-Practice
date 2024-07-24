//DFS
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, vector<int>& deltaRow, vector<int>& deltaCol, int n, int m) {
        grid[row][col] = '*'; // Mark as visited
        for (int i = 0; i < 4; i++) {
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == '1') {
                dfs(grid, nrow, ncol, deltaRow, deltaCol, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        vector<int> deltaRow = {-1, 0, +1, 0};
        vector<int> deltaCol = {0, -1, 0, +1};
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, deltaRow, deltaCol, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};


//BFS
class Solution {
public:
    void bfs(vector<vector<char>> &grid,int row,int col,vector<int> &deltaRow,vector<int> &deltaCol,int n,int m)
    {
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = '*';
        while(!q.empty())
        {
            auto [row,col] = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + deltaRow[i];
                int ncol = col + deltaCol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == '1')
                {
                    grid[nrow][ncol] = '*';
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        vector<int> deltaRow = {-1,0,+1,0};
        vector<int> deltaCol = {0,-1,0,+1};
        int n = grid.size();
        int m = grid[0].size();
        queue<int> q;
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == '1')
                {
                    bfs(grid,i,j,deltaRow,deltaCol,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
