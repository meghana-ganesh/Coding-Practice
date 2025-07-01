//TC:O(n) SC:O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(n);
        if(k>n)
            k = k % n;
        for(int i=0;i<n;i++)
        {
            temp[i] = nums[(i-k+n)%n];
        }
        nums = temp;
    }
};
