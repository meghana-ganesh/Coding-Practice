#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) 
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    if(n == 0 && m == 0)
        return 0;
    int min_sum = 0;
    int left,up;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)
                dp[i][j] = grid[i][j];
            else
            {
                if(j>0)
                    left = dp[i][j-1] + grid[i][j];
                if(i>0)
                    up = dp[i-1][j] + grid[i][j];
                dp[i][j] = min(left,up);
            }
            
        }
    }
    return dp[n-1][m-1];
}
