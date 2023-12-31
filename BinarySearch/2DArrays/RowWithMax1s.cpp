int lowerBound(vector<int> arr,int n,int x)
{
    int l=0,u=n-1;
    while(l <= u)
    {
        int mid = l + (u-l)/2;
        if(arr[mid] >= x)
            u = mid-1;
        else if(arr[mid] < x)
            l = mid+1;       
    }
    return l;
}
//we can take lowerbound(1) or upperbound(0)
//lowerbound(x) is index such that arr[ind] >= x
//upperbound(x) is index such that arr[ind] > x

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int cnt_max = -1;
    int index = -1;
    for(int i=0;i<n;i++)
    {
        int cnt_ones = m - lowerBound(matrix[i],m,1);
        if(cnt_ones > cnt_max)
        {
            index = i;
            cnt_max = cnt_ones;
        }
    }
    return index;
}
