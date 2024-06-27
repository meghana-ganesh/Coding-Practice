//TC: O(N*N)
//SC: O(N*N)
class Solution {
public:
    int helper(vector<int> &nums,vector<vector<int>> &dp,int ind,int prevInd)
    {
        if(ind == nums.size())
            return 0;
        if(dp[ind][prevInd+1] != -1)
            return dp[ind][prevInd+1];
        int len = 0 + helper(nums,dp,ind+1,prevInd);
        if(prevInd == -1 || nums[ind] > nums[prevInd])
        {
            len = max(len,1+helper(nums,dp,ind+1,ind));
        }
        return dp[ind][prevInd+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(nums,dp,0,-1);
    }
};
