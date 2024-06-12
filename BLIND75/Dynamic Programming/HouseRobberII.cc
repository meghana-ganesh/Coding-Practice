//TC:O(N)
class Solution {
public:
    int robHelper(vector<int>& nums, int start, int end) {
        int rob1 = 0, rob2 = 0;
        //[rob1,rob2,n,n+1,....]
        for (int i = start; i <= end; ++i) {
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
    
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        int maxsum1 = robHelper(nums, 0, nums.size() - 2);
        int maxsum2 = robHelper(nums, 1, nums.size() - 1);
        
        return max(maxsum1, maxsum2);
    }
};
