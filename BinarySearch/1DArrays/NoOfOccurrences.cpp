#include<bits/stdc++.h>
int lower_bound(vector<int> &arr,int n,int x,int l,int u,int *minx,int *first)
{
	if(l<=u)
	{
		int mid = l + (u-l)/2;
		if(arr[mid] >= x && arr[mid] <= *minx)
		{
			*first = mid;
			*minx = arr[mid];
			return lower_bound(arr,n,x,l,mid-1,minx,first);
		}
		else if(arr[mid] < x)
			return lower_bound(arr,n,x,mid+1,u,minx,first);
	}
	return *first;
}

int upper_bound(vector<int> &arr,int n,int x,int l,int u,int *minx1,int *last)
{
	if(l<=u)
	{
		int mid = l + (u-l)/2;
		if(arr[mid] > x && arr[mid] <= *minx1)
		{
			*last = mid;
			*minx1 = arr[mid];
			return upper_bound(arr,n,x,l,mid-1,minx1,last);
		}
		else if(arr[mid] <= x)
			return upper_bound(arr,n,x,mid+1,u,minx1,last);
	}
	return *last;
}

int count(vector<int>& arr, int n, int x) 
{
	// Write Your Code Here
	int minx = INT_MAX,minx1 = INT_MAX;
	int first = n,last = n;
	lower_bound(arr,n,x,0,n-1,&minx,&first);
	upper_bound(arr,n,x,0,n-1,&minx1,&last);
	if(first == n || arr[first] != x)
		return 0;
	else
		return last-1-first+1;
}
