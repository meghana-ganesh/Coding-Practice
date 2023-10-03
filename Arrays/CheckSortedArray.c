int isSorted(int n, vector<int> arr) 
{
    // Write your code here.
    int prev = INT_MIN;;
    int flag = 1;
    for(int i=0;i<n;i++)
    {
        if(arr[i] < prev)
        {
            flag = 0;
            break;
        }
        prev = arr[i];
    }
    return flag;
}
