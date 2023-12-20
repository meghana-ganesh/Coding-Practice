#include<bits/stdc++.h>
int find_sum(vector<int> &arr,int div)
{
	int sum=0;
	for(int i=0;i<arr.size();i++)
	{
		sum += ceil((double)arr[i]/(double)div);
	}
	return sum;
}
int binary_search(vector<int> &arr,int limit,int l,int u)
{
	int ans = -1;
	while(l<=u)
	{
		int mid = l + (u-l)/2;
		int sum = find_sum(arr,mid);
		if(sum <= limit)
		{
			ans = mid;
			u = mid-1;
		}
		else if(sum > limit)
			l = mid+1;
	}
	return ans;
}

int smallestDivisor(vector<int>& arr, int limit)
{
	// Write your code here.
	return binary_search(arr,limit,1,*max_element(arr.begin(),arr.end()));
}
