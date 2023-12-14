#include<bits/stdc++.h>

int binary_search(vector<int> &arr,int l,int u,int *minx)
{
	if(l<=u)
	{
		int mid = l + (u-l)/2;//5+(9-5)/2 = 
		if(arr[l] <= arr[mid])
		{
			if(arr[l] < *minx)
				*minx = arr[l];
			return binary_search(arr,mid+1,u,minx);
		}
		else
		{
			if(arr[mid] < *minx)
				*minx = arr[mid];
			return binary_search(arr,l,mid-1,minx);
		}
	}
	return *minx;
}

int findMin(vector<int>& arr)
{
	// Write your code here.
	int minx = INT_MAX;
	return binary_search(arr,0,arr.size()-1,&minx);
}
