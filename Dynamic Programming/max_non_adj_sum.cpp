//Maximum sum of non-adjacent elements
#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n+1,0);
    if(n == 1)
        return nums[0];
    if(n <= 0)
        return 0;
    dp[0] = nums[0];
    dp[1] = max(nums[1],nums[0]);
    for(int i=2;i<=n;i++)
    {
        int pick = nums[i] + dp[i-2];
        int not_pick = 0 + dp[i-1];
        dp[i] = max(pick,not_pick);
    }
    return dp[n-1];    
}
//DP[0] = 5
//dp[1] = 6
//dp[2] = max(6+5,6)
