#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,0);
    // Write your code here.
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(heights[1] - heights[0]);
    for(int i=3;i<=n;i++)
    {
        int left = dp[i-1] + abs(heights[i-1] - heights[i-2]);
        int right = dp[i-2] + abs(heights[i-1] - heights[i-3]);
        dp[i] = min(left,right);
    }
    return dp[n];    
}
