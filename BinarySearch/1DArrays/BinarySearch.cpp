int binary_search(vector<int> &nums,int target,int l,int u)
{
    int n = nums.size();
    int m = l + (u-l) /2;
    if(l <= u)
    {
        if(nums[m] == target)
            return m;
        else if(target > nums[m])
            return binary_search(nums,target,m+1,u);
        else
            return binary_search(nums,target,l,m-1);
    }
    return -1;
    
}

int search(vector<int> &nums, int target) 
{
    // Write your code here.
    int n = nums.size();
    int m = binary_search(nums,target,0,n-1);
    return m;
}
