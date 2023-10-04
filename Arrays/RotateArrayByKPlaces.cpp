//REVERSAL ALGORITHM
//TIME COMPLEXITY:O(N)
//SPACE COMPLEXITY:O(1)

vector<int> rotateArray(vector<int>arr, int k) 
{
    // Write your code here.
    int n = arr.size();
    k = k % n;
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
    reverse(arr.begin(),arr.end());
    return arr;
}
//12345
//32154
//45123


//TIME COMPLEXITY:O(N)
//SPACE COMPLEXITY:O(N)
vector<int> rotateArray(vector<int>arr, int k) 
{
    // Write your code here.
    if (arr.empty() || arr.size() == 1) 
    {
        return arr;
    }

    int n = arr.size();
    k = k % n;
    vector<int> rotated(n);

    for (int i = 0; i < n; ++i) 
    {
        int newIndex = (i - k + n) % n;
        rotated[newIndex] = arr[i];
    }

    // Copy rotated elements back to the original array
    for (int i = 0; i < n; ++i) 
    {
        arr[i] = rotated[i];
    }
    return arr;
}

//or
/*
    Time Complexity: O(n*k)
    Space Complexity: O(1)
    where n is the size of the input array.
*/

vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();
    for (int i = 0; i < k; i++) {
        int temp = arr[0];
        for (int j = 0; j < n - 1; j++)
            arr[j] = arr[j + 1];

        arr[n - 1] = temp;
    }

    return arr;
}
