#include<bits/stdc++.h>

int binary_search(vector<int> &arr,int l,int u,int *minx,int *min_idx)
{
    if(l<=u)
    {
        int mid = l + (u-l)/2;
        if(arr[l] <= arr[mid])
        {
            if(arr[l] < *minx)
            {
                *minx = arr[l];
                *min_idx = l;
            }
            return binary_search(arr,mid+1,u,minx,min_idx);
        }
        else
        {
            if(arr[mid] < *minx)
            {
                *minx = arr[mid];
                *min_idx = mid;
            }
            return binary_search(arr,l,mid-1,minx,min_idx);
        }
    }
    return *min_idx;
}

int findKRotation(vector<int> &arr)
{
    // Write your code here.
    int minx = INT_MAX;
    int min_idx = INT_MIN;
    return binary_search(arr,0,arr.size()-1,&minx,&min_idx);
}
