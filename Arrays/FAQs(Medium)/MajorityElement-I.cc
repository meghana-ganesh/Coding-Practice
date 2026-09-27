// hint: count = candidate's advantage, not frequency. we cancel advantageous element against others to be left with more of it. 
//eg. of 'advantageous' element is it occurs n/2 times. suppose array size 7, advantageis more than 7/2 = 3 times. so say 4. element 2 occurs 4 times out of 7 so it is bound to cancel the other 3.


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ele = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(count == 0)
                ele = nums[i];
            count += (ele == nums[i]) ? 1 : -1;
        }
        return ele;
    }
};

//why at the end we get the exact majority element?
// M X
// M X
// M X
// M X
// M
//four M's were cancelled.
//But One M must survive.

// That's why the majority element cannot be completely eliminated,and last element that was set at count = 0 is the majority one.
