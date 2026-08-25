//TC: Best,Average Case - O(NlogN), Worst Case: O(N^2)

class Solution {
public:
    int findPivot(vector<int> &nums,int low,int high)
    {
        int pivot = low;
        int i = low;
        int j = high;
        while(i < j)
        {
            while(i <= high && nums[i] <= nums[pivot] )
                i++;
            while(j >= low + 1 && nums[j] >= nums[pivot] )
                j--;
            if(i < j)
                swap(nums[i],nums[j]);
        }
        swap(nums[j],nums[pivot]);
        return j;
    }
    void quickSort(vector<int> &nums,int i,int j)
    {
        if(i < j)
        {
            int pIndex = findPivot(nums,i,j);
            quickSort(nums,i,pIndex-1);
            quickSort(nums,pIndex+1,j);
        }
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        int low = 0;
        int high = nums.size()-1;
        quickSort(nums,low,high);
        return nums;
    }
};

//But this gave a restrictions failed, pivot needs to be randomised to avoid worst case O(N^2) in more cases
//also we get TLE after randomising, so for that three way partition was applied
