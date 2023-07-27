#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) 
{
    //  Write your code here.
    vector<int> dp(nStairs + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= nStairs; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }

    return dp[nStairs];
}
