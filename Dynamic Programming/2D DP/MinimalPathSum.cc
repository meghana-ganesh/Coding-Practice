//TLE USING MEMOIZATION
class Solution {
public:
    int helper(vector<vector<int>> &matrix,int n,int row,int col,vector<vector<int>> &dp)
    {
        if(col >= n || col < 0)
        {
            return INT_MAX;
        }
        if(row == n-1)
            return matrix[row][col];
        if(dp[row][col] != -1)
            return dp[row][col];
        return dp[row][col] = matrix[row][col] + min({helper(matrix,n,row+1,col-1,dp),helper(matrix,n,row+1,col,dp),helper(matrix,n,row+1,col+1,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int minVal = INT_MAX;
        if (n == 0) 
        {
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            minVal = min(minVal,helper(matrix,n,0,i,dp));
        }
        return minVal;
    }
};
