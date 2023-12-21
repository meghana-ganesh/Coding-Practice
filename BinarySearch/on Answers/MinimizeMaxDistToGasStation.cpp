#include <bits/stdc++.h>

using namespace std;

int find_gasstation_count(vector<int> &arr, long double dist) 
{
    int count = 0;
    for (int i = 1; i < arr.size(); i++) 
	{
        int NoInBetween = (arr[i] - arr[i - 1]) / dist;
        if ((arr[i] - arr[i - 1]) == (NoInBetween * dist)) 
		{
            NoInBetween--;
        }
        count += NoInBetween;
    }
    return count;
}

double binary_search(vector<int> &arr, int k, long double l, long double u) {
    long double diff = 1e-6;
    while (u - l > diff) 
	{
        long double mid = l + (u-l)/ 2.0;
        int count = find_gasstation_count(arr, mid);
        if (count > k) 
            l = mid;
		else if (count <= k)
		{
            u = mid;
        }
    }
    return (double)u;
}

double minimiseMaxDistance(vector<int> &arr, int k) 
{
    // Write your code here.
    long double max_consecutive_dist = 0;
    for (int i = 0; i < arr.size() - 1; i++) 
	{
        max_consecutive_dist = max(max_consecutive_dist, (long double)(arr[i + 1] - arr[i]));
    }
    return binary_search(arr, k, (long double)0, max_consecutive_dist);
}
