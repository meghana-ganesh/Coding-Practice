void helper(int n,vector<int> &nums,int start,int end)
{
    if(start<end)
    {
        swap(nums[start],nums[end]);
        helper(n,nums,start+1,end-1);
    }
}
vector<int> reverseArray(int n, vector<int> &nums)
{
    // Write your code here.
    int start = 0,end = n-1;
    helper(n,nums,start,end);
    return nums;
}
