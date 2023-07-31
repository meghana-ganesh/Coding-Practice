#include<math.h>
int mazeObstacles(int n, int m, vector<vector<int>> &mat) 
{
    // Write your code here
    vector<vector<int>> dp(n,vector<int>(m,0));
    if(m <= 0 || n <= 0)
    {
        return 0;
    }  
    if(mat[0][0] == -1)
        return 0;
    dp[0][0] = 1;
    for(int i=0;i<n;i++)
    {
        if(mat[i][0] != -1)
            dp[i][0] = 1;
        else
            break;
    }
    for(int j=0;j<m;j++)
    {
        if(mat[0][j] != -1)
            dp[0][j] = 1;
        else
            break;
    }  
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(mat[i][j] != -1)
            {
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 1000000007;
            }
        }
    }
    //0 0 0 
    //0-1 0 
    //0 0 0 
    return dp[n-1][m-1];
}
