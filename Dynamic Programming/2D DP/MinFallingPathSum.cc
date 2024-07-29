//FIXED TO INITIALIZE DP ARRAY TO INT_MIN INSTEAD OF -1
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
        if(dp[row][col] != INT_MIN)
            return dp[row][col];
        return dp[row][col] = matrix[row][col] + min({helper(matrix,n,row+1,col-1,dp),helper(matrix,n,row+1,col,dp),helper(matrix,n,row+1,col+1,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
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




//TLE USING MEMOIZATION BECAUSE THE GIVEN TC HAD -1S IN IT WITH MANY 0'S, SINCE WE HAVE A CHECK TO COMPUTE IF DP[ROW][COL] IS STILL -1, IT WAS COMPUTING AGAIN AND AGAIN AND GIVING TLE
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
