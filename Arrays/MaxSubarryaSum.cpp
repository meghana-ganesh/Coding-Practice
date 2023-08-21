#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    if(n == 0)
        return 0;
    long long prevsum = arr[0],maxsum = arr[0];
    int allnegative = 1;
    for(int i=1;i<n;i++)
    {
        prevsum = max((long long)arr[i],prevsum+arr[i]);
        maxsum = max(maxsum,prevsum);
        if(arr[i] >= 0)
            allnegative = 0;
    }
    if(allnegative)
        return 0;
    return maxsum;
}
