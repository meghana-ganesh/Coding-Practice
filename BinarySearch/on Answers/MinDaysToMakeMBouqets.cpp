#include<bits/stdc++.h>
int possible(vector<int> arr,int k,int m,int day)
{
	int count=0;
	int noofB=0;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i] <= day)
			count++;
		else
		{
			noofB += (count/k);
			count = 0;
		}
	}
	noofB += (count/k);
	if(noofB >= m)
		return 1;
	else
		return 0;
}

int binary_search(vector<int> arr,int k,int m,int l,int u)
{
	int ans=u;
	if(m*k > arr.size())
		return -1;
	while(l<=u)
	{
		int mid = l + (u-l)/2;
		if(possible(arr,k,m,mid) == 1)
		{
			ans = mid;
			u = mid-1;
		}
		else
			l = mid+1;
	}
	return ans;
}

int roseGarden(vector<int> arr, int k, int m)
{
	// Write your code here
	int mini = INT_MAX;
	int maxi = INT_MIN;
	for(int i=0;i<arr.size();i++)
	{
		maxi = max(maxi,arr[i]);
		mini = min(mini,arr[i]);
	}
	return binary_search(arr,k,m,mini,maxi);
}
