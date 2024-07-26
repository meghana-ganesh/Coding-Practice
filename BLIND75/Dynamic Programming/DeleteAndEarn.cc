//TC:O(N^2)+O(logN) = O(N^2)

class Solution {
public:
    int helper(vector<int> &nums,int n,int ind,vector<int> &dp)
    {
        if(ind >= n)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        int curVal = nums[ind];
        int i = ind+1;
        int sum = curVal;
        while(i < n && nums[i] == curVal)
        {
            sum += nums[i];
            i++;
        }
        while(i < n && nums[i] == nums[ind]+1)
        {
            i++;
        }
        return dp[ind] = max(sum+helper(nums,n,i,dp),helper(nums,n,ind+1,dp));
    }
    int deleteAndEarn(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        sort(nums.begin(),nums.end());
        return helper(nums,n,0,dp);
    }
};
