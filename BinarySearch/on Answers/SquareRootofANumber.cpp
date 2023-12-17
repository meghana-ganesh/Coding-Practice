int binary_search(int n,int l,int u)
{
    int ans;
    while(l<=u)
    {
        long long mid = l + (u-l)/2;
        if(mid*mid > n)
            u = mid-1;
        else if(mid*mid < n)
        {
            ans = mid;
            l = mid + 1;
        }
        else if(mid*mid == n)
            return mid;
    }
    return ans;
}

int floorSqrt(int n)
{
    // Write your code here.
    return binary_search(n,1,n); 
}
