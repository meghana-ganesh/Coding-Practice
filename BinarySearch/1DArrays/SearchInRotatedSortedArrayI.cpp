int binary_search(vector<int> &arr,int n,int k,int l,int u)
{
    if(l<=u)
    {
        int mid = l + (u-l)/2;
        if(arr[mid] == k)
            return mid;
        else
        {
            if(arr[l]<arr[mid])
            {
                if(k>=arr[l] && k<arr[mid])  
                {
                    return binary_search(arr,n,k,l,mid-1);
                }
                else
                    return binary_search(arr,n,k,mid+1,u);              
            }
            else
            {
                if(k>arr[mid] && k<=arr[u])
                {
                    return binary_search(arr,n,k,mid+1,u);
                }
                else
                    return binary_search(arr,n,k,l,mid-1);
            }
        }
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    return binary_search(arr,n,k,0,n-1);
}
