class Solution {
public:
    //TC:O(N) SC:O(1)
    //logic is to find more than 1 unsorted pair, 
    //if more than 1 such pairs exist its not a rotated sorted array
    bool check(vector<int>& nums) 
    {
        int count = 0;
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1] > nums[i])
                count++;
        }
        //since we started loop from i = 1, it checks for -
        //0 -> 1

        // 1 -> 2

        // …

        // n - 2 -> n - 1

        // But misses:

        // n - 1 -> 0 (the wraparound)
        if(nums[n-1] > nums[0]) 
            count++;
        return count <= 1;
    }
};
