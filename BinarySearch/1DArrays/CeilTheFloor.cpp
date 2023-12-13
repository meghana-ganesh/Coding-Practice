int ceil(vector<int> &arr,int n,int x,int l,int u,int *ans,int *minx)
{
	if(l<=u)
	{
		int mid = l + (u-l)/2;
		if(arr[mid] >= x && arr[mid] <= *minx)
		{
			*ans = arr[mid];
			ceil(arr,n,x,l,mid-1,ans,minx);
		}
		else if(arr[mid] < x)
			ceil(arr,n,x,mid+1,u,ans,minx);
	}
	return *ans;
}

int floor(vector<int> &arr,int n,int x,int l,int u,int *ans,int *maxx)
{
	if(l<=u)
	{
		int mid = l + (u-l)/2;
		if(arr[mid] <= x && arr[mid] >= *maxx)
		{
			*ans = arr[mid];
			floor(arr,n,x,mid+1,u,ans,maxx);
		}
		else if(arr[mid] > x)
			floor(arr,n,x,l,mid-1,ans,maxx);
	}
	return *ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
	// Write your code here.
	int ans1 = -1;
	int ans2 = -1;
	int minx = INT_MAX;
	int maxx = INT_MIN;
	pair<int,int> p;
	p.first = floor(a,n,x,0,n-1,&ans1,&maxx);
	p.second = ceil(a,n,x,0,n-1,&ans2,&minx);
	return p;
}
