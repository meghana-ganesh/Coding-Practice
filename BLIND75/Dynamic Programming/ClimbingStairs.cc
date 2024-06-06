//TC:O(2^N)
//If you draw the tree you will see the no. of ways coming in Fibonacci pattern
//TLE issue
class Solution {
public:
    int climbStairs(int n) 
    {
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;
        int left = climbStairs(n-1);
        int right = climbStairs(n-2);
        return left+right;
    }
};

//MEMOIZATION
//TC:O(N)
//SC:O(N) unordered map
class Solution {
public:
    int helper(int n,unordered_map<int,int> &mpp)
    {
        if(n == 0 || n == 1)
            return 1;
        if(mpp.find(n) == mpp.end())
            mpp[n] = helper(n-1,mpp)+helper(n-2,mpp);
            return mpp[n];
    }
    int climbStairs(int n) 
    {
        unordered_map<int,int> mpp;
        return helper(n,mpp);
    }
};

//TABULARIZATION\
//TC - O(N)
//SC - O(N) dp array
class Solution {
public:
    int climbStairs(int n) 
    {
        if(n == 0 || n == 1)
            return 1;
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

//SPACE OPTIMIZATION
//TC- O (N)
class Solution {
public:
    int climbStairs(int n) 
    {
        if(n == 0 || n == 1)
            return 1;
        vector<int> dp(n+1);
        int prev = 1,curr = 1;
        for(int i=2;i<=n;i++)
        {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};
