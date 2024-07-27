//TC:O(N*M)
//SC:O(N*M)
class Solution {
public:
    int helper(vector<vector<int>> &obstacleGrid,int n,int m,int row,int col,vector<vector<int>> &dp)
    {
        if(row == n-1 && col == m-1)
        {
            if(obstacleGrid[row][col] == 1)
                return 0;
            return 1;
        }
        if(row >= n || col >= m)
            return 0;
        if(obstacleGrid[row][col] == 1)
            return 0;
        if(dp[row][col] != -1)
            return dp[row][col];
        int down = helper(obstacleGrid,n,m,row+1,col,dp);
        int right = helper(obstacleGrid,n,m,row,col+1,dp);
        return dp[row][col] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(obstacleGrid,n,m,0,0,dp);
    }
};
