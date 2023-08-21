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


//USING DIVIDE AND CONQUER
#include <bits/stdc++.h> 
using namespace std;

long long maxSubarraySum(int arr[], int left, int right) {
    if (left == right) {
        return arr[left];
    }

    int mid = (left + right) / 2;
    
    // Calculate the maximum subarray sum that crosses the midpoint
    long long maxLeftSum = INT_MIN;
    long long sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        maxLeftSum = max(maxLeftSum, sum);
    }
    
    long long maxRightSum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        maxRightSum = max(maxRightSum, sum);
    }
    
    // Calculate the maximum subarray sum in the left and right halves
    long long maxLeftHalf = maxSubarraySum(arr, left, mid);
    long long maxRightHalf = maxSubarraySum(arr, mid + 1, right);
    
    // Return the maximum of three possible cases: left, right, or across midpoint
    return max({maxLeftHalf, maxRightHalf, maxLeftSum + maxRightSum});
}
