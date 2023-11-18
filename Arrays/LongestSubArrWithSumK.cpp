#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) 
{
    // Write your code here
    int n = a.size();
    int s = 0, e = 0;
    long long sum = a[0];
    int maxlen = 0;

    while (e < n)
    {

        while (s <= e && sum > k)
        {
            sum -= a[s];
            s++;
        }

        if (sum == k)
        {
            maxlen = max(maxlen,e - s + 1);
        }

        e++;
        if(e<n)
            sum += a[e];
    }

    return maxlen;
}
//sum=1
//sum=3
//maxlen = 2
//s=1 e=1 sum = 0
//sum = 1 e = 2
//sum = 4 e=3
//sum=0 s = 3
//
