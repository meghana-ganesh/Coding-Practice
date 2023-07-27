#include <bits/stdc++.h> 
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    vector<long long int> dp1(n+1,0);
    if(n == 1)
        return valueInHouse[0];
    if(n == 2)
        return max(valueInHouse[0],valueInHouse[1]);
    if(n <= 0)
        return 0;
    //robs 1st house but not last house
    dp1[0] = valueInHouse[0];
    dp1[1] = max(valueInHouse[0],valueInHouse[1]);
    for(int i=2;i<n-1;i++)
    {
        long long int pick = valueInHouse[i] + dp1[i-2];
        long long int not_pick = 0 + dp1[i-1];
        dp1[i] = max(pick,not_pick);
    }
    //dp1[2] = 59+41 = 100
    //dp1[3] = 26+53 = 79
    //dp1[4] = 17+41 = 58
    //dp1[5] = 13+26 = 39
    //dp1[6] = 

    vector<long long int> dp2(n + 1, 0);
    //robs 2nd house but not first house
    dp2[0] = 0;
    dp2[1] = valueInHouse[1];
    for (int i = 2; i < n; i++) 
    {
        long long int pick = valueInHouse[i] + dp2[i - 2];
        long long int not_pick = dp2[i - 1];
        dp2[i] = max(pick, not_pick);
    }
    return max(dp1[n-2],dp2[n-1]);
}
