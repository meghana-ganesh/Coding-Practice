#include<bits/stdc++.h>
using namespace std;
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,0));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max({points[0][0],points[0][1],points[0][2]});
    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            for(int task=0;task<3;task++)
            {
                if(task != last)
                {
                    int pnt = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],pnt);
                }
            }
        }
    }
    return dp[n-1][3];
}
