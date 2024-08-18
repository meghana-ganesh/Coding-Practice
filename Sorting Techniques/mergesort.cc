//TC:O(NlogN)
//SC:O(N)
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
        int low = l;
        int high = m+1;
        vector<int> temp;
        while(low <= m && high <= r)
        {
            if(arr[low] <= arr[high])
            {
                temp.push_back(arr[low]);
                low++;
            }
            else
            {
                temp.push_back(arr[high]);
                high++;
            }
        }
        while(low <= m)
        {
            temp.push_back(arr[low]);
            low++;
        }
        while(high <= r)
        {
            temp.push_back(arr[high]);
            high++;
        }
        for(int i=l;i<=r;i++)
        {
            arr[i] = temp[i-l];
        }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l >= r)
            return;
        int mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};
