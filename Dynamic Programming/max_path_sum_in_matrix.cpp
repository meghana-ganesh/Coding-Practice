#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int j=0;j<m;j++)
    {
        dp[n-1][j] = matrix[n-1][j];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            int down = matrix[i][j] + dp[i+1][j];
            int left_diag = (j>0) ? (matrix[i][j] + dp[i+1][j-1]):INT_MIN; //conditional way uses less memory
            int right_diag = (j<m-1) ? (matrix[i][j] + dp[i+1][j+1]):INT_MIN;
            dp[i][j] = max({down,left_diag,right_diag});
            
        }
    }
    int max_sum = INT_MIN;
    for(int j=0;j<m;j++)
    {
        if(dp[0][j] > max_sum)
            max_sum = dp[0][j];
    }
    return max_sum;
}
