//TC:O(N*M)
class Solution {
public:
    int helper(int m,int n,int row,int col,vector<vector<int>> &dp)
    {
        if(row == m-1 && col == n-1)
            return 1;
        else if(row >= m || col >= n)
            return 0; 
        if(dp[row][col] != -1)
            return dp[row][col];
        return dp[row][col] = helper(m,n,row+1,col,dp) + helper(m,n,row,col+1,dp);
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m,n,0,0,dp);
    }
};
