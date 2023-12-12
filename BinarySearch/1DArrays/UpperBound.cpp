#include<bits/stdc++.h>
int binary_search(vector<int> &arr,int x,int n,int l,int u,int *min_ind,int *minx)
{
	if(l<=u)
	{
		int mid = l + (u-l)/2;
		if(arr[mid] > x && arr[mid] <= *minx)
		{
			*minx = arr[mid];
			*min_ind = mid;
			binary_search(arr,x,n,l,mid-1,min_ind,minx);
		}
		else if(arr[mid] <= x)
		{
			binary_search(arr,x,n,mid+1,u,min_ind,minx);
		}
	}
	return *min_ind;
}

int upperBound(vector<int> &arr, int x, int n)
{
	// Write your code here.
	int min_ind = n;
	int minx = INT_MAX;
	binary_search(arr,x,n,0,n-1,&min_ind,&minx);
	return min_ind;	
}
//0+2 = 2
//3 4
