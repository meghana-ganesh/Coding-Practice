#include<bits/stdc++.h>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n1, int n2, int k)
{
    // Write your code here
    if(n1 > n2)
        return kthElement(arr2,arr1,n2,n1,k);
    int l = max(0,k-n2),u = min(k,n1);
    int left = k;
    while(l <= u)
    {
        int mid1 = l + (u-l)/2;
        int mid2 = left - mid1;
        int l1 = INT_MIN,l2 = INT_MIN;
        int r1 = INT_MAX,r2 = INT_MAX;
        if(mid1 < n1)
            r1 = arr1[mid1];
        if(mid2 < n2)
            r2 = arr2[mid2];
        if(mid1-1 >= 0)
            l1 = arr1[mid1-1];
        if(mid2-1 >= 0)
            l2 = arr2[mid2-1];
        if(l1 <= r2 && l2 <= r1)
            return max(l1,l2);
        if(l1 > r2)
            u = mid1-1;
        else
            l = mid1+1;
    }
    return -1;
}
