//iterative binary search
int binary_search(vector<int> &arr,int n,int l,int u)
{
	while(l<=u)
	{
		int mid = l + (u-l)/2;
		if(arr[mid-1] != arr[mid] && arr[mid+1] != arr[mid])
		{
			return arr[mid];
		}
		if((mid%2==1) && arr[mid-1] == arr[mid])
		{
			l = mid+1;
		}
		else if((mid%2==0) && arr[mid+1] == arr[mid])
		{
			l = mid+1;
		}
		else
			u = mid-1;
	}
}


int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int n = arr.size();
	if(arr[0] != arr[1])
		return arr[0];
	else if(arr[n-1] != arr[n-2])
		return arr[n-1];
	return binary_search(arr,n,0,n-1);
}





//recursive binary search
int binary_search(vector<int> &arr,int n,int l,int u)
{
	if(l<=u)
	{
		int mid = l + (u-l)/2;
		if(arr[mid-1] != arr[mid] && arr[mid+1] != arr[mid])
		{
			return arr[mid];
		}
		if((mid%2==1) && arr[mid-1] == arr[mid])
		{
			return binary_search(arr,n,mid+1,u);
		}
		else if((mid%2==0) && arr[mid+1] == arr[mid])
		{
			return binary_search(arr,n,mid+1,u);
		}
		else
			return binary_search(arr,n,l,mid-1);
	}
}


int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int n = arr.size();
	if(arr[0] != arr[1])
		return arr[0];
	else if(arr[n-1] != arr[n-2])
		return arr[n-1];
	return binary_search(arr,n,0,n-1);
}
