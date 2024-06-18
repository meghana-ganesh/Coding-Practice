//normal O(N^2) traverse 2 for loops
//sort and traverse to check if next ele is also equal,O(N)
//use set
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        set<int> mpp;
        for(int i=0;i<nums.size();i++)
        {
            if(mpp.find(nums[i]) != mpp.end())
                return true;
            mpp.insert(nums[i]);
        }
        return false;
    }
};
