bool binary_search(vector<int> &arr, int k, int l, int u) 
{
    if (l <= u) 
    {
        int mid = l + (u - l) / 2;
        if (arr[mid] == k) 
        {
            return true;
        }

        // Handle the case where arr[mid] is equal to arr[u] and arr[l]
        while (arr[mid] == arr[u] && arr[mid] == arr[l] && l<u)
        {
            l = l + 1;
            u = u - 1;
        }

        if (arr[l] < arr[mid]) 
        {
            if (k >= arr[l] && k < arr[mid]) 
            {
                return binary_search(arr, k, l, mid - 1);
            }
            else 
            {
                return binary_search(arr, k, mid + 1, u);
            }
        } 
        else if (arr[l] > arr[mid]) 
        {
            if (k > arr[mid] && k <= arr[u]) 
            {
                return binary_search(arr, k, mid + 1, u);
            }
            else 
            {
                return binary_search(arr, k, l, mid - 1);
            }
        }
        else
        {
            return binary_search(arr, k, l + 1, u);
        }
    }
    return false;
}

bool searchInARotatedSortedArrayII(vector<int> &A, int key) 
{
    return binary_search(A, key, 0, A.size() - 1);
}
