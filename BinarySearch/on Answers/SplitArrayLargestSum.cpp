int find_count(vector<int> a,int k,int maxsum)
{
    int subarrcount = 1,sum = 0;
    for(int i=0;i<a.size();i++)
    {
        if(sum + a[i] <= maxsum)
            sum += a[i];
        else
        {
            subarrcount++;
            sum = a[i];
        }
    }
    return subarrcount;
}
int binary_search(vector<int> a,int k,int l,int u)
{
    while(l<=u)
    {
        int mid =  l + (u-l)/2;
        int subarrcount = find_count(a,k,mid);
        if(subarrcount > k)
            l = mid+1;
        else if(subarrcount <= k)
            u = mid-1;
    }
    return l;
}
int largestSubarraySumMinimized(vector<int> a, int k) 
{
    // Write Your Code Here
    int sum = 0;
    for(int i=0;i<a.size();i++)
    {
        sum += a[i];
    }
    return binary_search(a,k,*max_element(a.begin(),a.end()),sum);
}
