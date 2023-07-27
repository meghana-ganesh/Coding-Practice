int helper(int ind,int last,vector<vector<int>> &points,vector<vector<int>> &dp)
{
    int maxi;
    if(ind == 0)
    {
        maxi = 0;
        for(int i=0;i<3;i++)
        {
            if(i != last)
            {
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[ind][last] != -1)
        return dp[ind][last];
    maxi = 0;
    for(int i=0;i<3;i++)
    {
        if(i != last)
        {
            int total_points = points[ind][i] + helper(ind-1,i,points,dp);
            maxi = max(maxi,total_points);
        }
    }
    dp[ind][last] = maxi;
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    //n:no of days
    //last:no of activities
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return helper(n-1,3,points,dp);
}

