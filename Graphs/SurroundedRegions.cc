//TC:O(N*M)
//SC:O(N*M) - recursion stack
class Solution {
public:
    void dfs(vector<vector<char>> &board,vector<int> &deltaRow,vector<int> &deltaCol,int n,int m,int row,int col)
    {
        board[row][col] = '*';
        for(int i=0;i<4;i++)
        {
            int nrow = row + deltaRow[i];
            int ncol = col + deltaCol[i];
            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && board[nrow][ncol] == 'O')
            {
                dfs(board,deltaRow,deltaCol,n,m,nrow,ncol);
            }
        }
    }
    void solve(vector<vector<char>>& board) 
    {
        if(board.empty())
            return;
        vector<int> deltaRow = {-1,0,+1,0};
        vector<int> deltaCol = {0,-1,0,+1};
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            if (board[i][0] == 'O') 
                dfs(board,deltaRow, deltaCol, n, m, i, 0);
            if (board[i][m-1] == 'O') 
                dfs(board, deltaRow, deltaCol, n, m, i, m-1);
        }
        for(int j=0;j<m;j++)
        {
            if (board[0][j] == 'O') 
                dfs(board, deltaRow, deltaCol, n, m, 0, j);
            if (board[n-1][j] == 'O') 
                dfs(board, deltaRow, deltaCol, n, m, n-1, j);
        }
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (board[i][j] == 'O') 
                    board[i][j] = 'X';
                if (board[i][j] == '*') 
                    board[i][j] = 'O';
            }
        }
    }
};
//USING BFS
class Solution {
public:
    void bfs(vector<vector<char>>& board,vector<int> deltaRow,vector<int> deltaCol,int n,int m,int row,int col)
    {
        board[row][col] = '*';
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty())
        {
            auto [row,col] = q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow = row + deltaRow[i];
                int ncol = col + deltaCol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && board[nrow][ncol] == 'O')
                {
                    q.push({nrow,ncol});
                    board[nrow][ncol] = '*';
                }
            }
        }

    }
    void solve(vector<vector<char>>& board) 
    {
        if(board.empty())
            return;
        vector<int> deltaRow = {-1,0,+1,0};
        vector<int> deltaCol = {0,-1,0,+1};
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++)
        {
            if (board[i][0] == 'O') 
                bfs(board, deltaRow, deltaCol, n, m, i, 0);
            if (board[i][m-1] == 'O') 
                bfs(board, deltaRow, deltaCol, n, m, i, m-1);
        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j] == 'O')
                bfs(board,deltaRow,deltaCol,n,m,0,j);
            if(board[n-1][j] == 'O')
                bfs(board,deltaRow,deltaCol,n,m,n-1,j);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '*')
                    board[i][j] = 'O';
            }
        }
    }
};
