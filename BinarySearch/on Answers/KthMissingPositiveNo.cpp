int binary_search(vector<int> vec,int n,int k,int l,int u)
{
    while(l<=u)
    {
        int mid = l + (u-l)/2;
        int missing = vec[mid] - (mid+1);
        if(missing < k)
            l = mid+1;
        else
            u = mid-1;
    }
    return u+1+k; //l+k as l = u+1
}

int missingK(vector < int > vec, int n, int k) 
{
    // Write your code here.
    return binary_search(vec,n,k,0,n-1);
}
