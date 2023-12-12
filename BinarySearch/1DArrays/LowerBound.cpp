int binary_search(vector<int> arr, int n, int x, int l, int u, int *min_idx, int *minx) {
    if (l <= u) 
	{
        int mid = l + (u - l) / 2;
        if (arr[mid] >= x && arr[mid] <= *minx) 
		{
            *minx = arr[mid];
            *min_idx = mid;
        }

        if (arr[mid] >= x) 
		{
            return binary_search(arr, n, x, l, mid - 1, min_idx, minx);
        } 
		else 
		{
            return binary_search(arr, n, x, mid + 1, u, min_idx, minx);
        }
    }
    return *min_idx;
}

int lowerBound(vector<int> arr, int n, int x) 
{
    int min_idx = n;
    int minx = INT_MAX;
    return binary_search(arr, n, x, 0, n - 1, &min_idx, &minx);
}
