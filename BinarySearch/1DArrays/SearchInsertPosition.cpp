int binary_search(vector<int> &arr,int m,int l,int u,int *minx,int *min_idx)
{
	if(l<=u)
	{
		int mid = l + (u-l)/2;
		if(arr[mid] >= m && arr[mid] <= *minx)
		{
			*minx = arr[mid];
			*min_idx = mid;
			binary_search(arr,m,l,mid-1,minx,min_idx);
		}
		else if(arr[mid] < m)
			binary_search(arr,m,mid+1,u,minx,min_idx);
	}
	return *min_idx;
}
int searchInsert(vector<int>& arr, int m)
{
	// Write your code here.
	int minx = INT_MAX;
	int n = arr.size();
	int min_idx = n;
	binary_search(arr,m,0,n-1,&minx,&min_idx);
	return min_idx;
}
