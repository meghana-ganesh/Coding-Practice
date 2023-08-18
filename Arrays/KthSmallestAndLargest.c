//my code:
#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	vector<int> res;
	int max,min; 
	sort(arr.begin(),arr.end());
	min = arr[k-1];
	max = arr[n-k];
	res.push_back(min);
	res.push_back(max);
	return res;
}
//better without declaring min max
#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
	vector<int> res;
	int max,min; 
	sort(arr.begin(),arr.end());
	res.push_back(arr[k-1]);
	res.push_back(arr[n-k]);
	return res;
}
