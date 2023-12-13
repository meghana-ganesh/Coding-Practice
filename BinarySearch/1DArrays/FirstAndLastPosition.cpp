#include<bits/stdc++.h>
int lower_bound(vector<int> &arr,int n,int k,int l,int u,int *minx,int *first)
{
    if(l <= u)
    {
        int mid = l + (u-l)/2;
        if(arr[mid] >= k && arr[mid] <= *minx)
        {
            *minx = arr[mid];
            *first = mid;
            lower_bound(arr,n,k,l,mid-1,minx,first);
        }
        else if(arr[mid] < k)
            lower_bound(arr,n,k,mid+1,u,minx,first);
    }
    return *first;
}

int upper_bound(vector<int> &arr,int n,int k,int l,int u,int *minx1,int *last)
{
    if(l<=u)
    {
        int mid = l + (u-l)/2;
        if(arr[mid] > k && arr[mid] <= *minx1)
        {
            *minx1 = arr[mid];
            *last = mid;
            upper_bound(arr,n,k,l,mid-1,minx1,last);
        }
        else if(arr[mid] <= k)
            upper_bound(arr,n,k,mid+1,u,minx1,last);        
    }
    return *last;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int minx = INT_MAX,minx1 = INT_MAX;
    int first = n,last = n;
    lower_bound(arr,n,k,0,n-1,&minx,&first);
    upper_bound(arr,n,k,0,n-1,&minx1,&last);
    if(first == n || arr[first] != k)
        return{-1,-1};
    else
        return{first,last-1};
}
