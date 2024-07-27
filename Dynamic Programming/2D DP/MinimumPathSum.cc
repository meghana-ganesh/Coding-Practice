//TC:O(N*M)
//SC:O(N*M)
class Solution {
public:
    int helper(vector<vector<int>> &grid,vector<vector<int>> &dp,int row,int col,int n,int m)
    {
        if(row == n-1 && col == m-1)
        {
            return grid[n-1][m-1];
        }
        if(row >= n || col >= m)
            return INT_MAX;
        if(dp[row][col] != -1)
            return dp[row][col];
        int down = helper(grid,dp,row+1,col,n,m);
        int right = helper(grid,dp,row,col+1,n,m);
        return dp[row][col] = grid[row][col] + min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(grid,dp,0,0,n,m);
    }
};
