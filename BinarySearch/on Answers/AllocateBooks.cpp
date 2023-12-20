int student_count(vector<int> &arr,int n,int m,int pages)
{
    int stu=1,pagesstudent=0;
    for(int i=0;i<n;i++)
    {
        if(pagesstudent + arr[i] <= pages)
            pagesstudent += arr[i];
        else
        {
            stu++;
            pagesstudent = arr[i];
        }
    }
    return stu;
}

int binary_search(vector<int> &arr,int n,int m,int l,int u)
{
    if(m > n)
        return -1;
    while(l<=u)
    {
        int mid = l + (u-l)/2;
        int noofstu = student_count(arr,n,m,mid);
        if(noofstu > m)
            l = mid+1;
        else if(noofstu <= m)
            u = mid-1;
    }
    return l;
}

int findPages(vector<int>& arr, int n, int m)
{
    // Write your code here.
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    return binary_search(arr,n,m,*max_element(arr.begin(),arr.end()),sum);
}
