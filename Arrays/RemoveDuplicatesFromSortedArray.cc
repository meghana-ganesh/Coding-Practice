//NEEDS TO BE DONE IN PLACE

//Optimised approach

//TC:O(NlogN) - first thought approach

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        map<int,int> freq;
        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }
        int k = 0;
        int i = 0;
        for(auto [key,value] : freq)
        {
            k++;
            nums[i] = key;
            i++;
        }
        return k;
    }
};
