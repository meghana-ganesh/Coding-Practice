int binary_search(vector<int> &arr,int l,int u)
{
    while(l<=u)
    {
        int mid = l + (u-l)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
        {
            return mid;
        }
        else if(arr[mid] > arr[mid-1])
            l = mid+1;
        else if(arr[mid] > arr[mid+1])
            u = mid-1;
        else
            l = mid+1; //we can also write u = mid-1,this is the opposite of peak case for multiple peaks
    }
    return -1;
}

int findPeakElement(vector<int> &arr) 
{
    // Write your code here
    int n = arr.size();
    if(arr[0] > arr[1])
        return 0;
    else if(arr[n-1] > arr[n-2])
        return n-1;
    else
        return binary_search(arr,1,n-2);
}
