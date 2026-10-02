//Better Approach: TC:O(n) SC:O(n) but with 1 pass

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> ans(nums.size());

        int pos = 0;
        int neg = 1;

        for(int x : nums)
        {
            if(x > 0)
            {
                ans[pos] = x;
                pos += 2;
            }
            else
            {
                ans[neg] = x;
                neg += 2;
            }
        }

        return ans;
    }
};
//My approach: TC:O(n) SC:O(n) but with 2 passes

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        queue<int> positives;
        queue<int> negatives;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] >= 0)
                positives.push(nums[i]);
            else
                negatives.push(nums[i]);
        }
        if(nums[0] < 0)
        {
            if(!positives.empty())
            {
                nums[0] = positives.front();
                positives.pop();
            }
        }
        else
        {
            nums[0] = positives.front();
            positives.pop();
        }
        for(int i=1;i<nums.size();i++)
        {
           if(i % 2 == 0 && !positives.empty())
           {
                nums[i] = positives.front();
                positives.pop();
           }
           else if(i % 2 != 0 && !negatives.empty())
           {
                nums[i] = negatives.front();
                negatives.pop();
           }
        }
        return nums;
    }
};
