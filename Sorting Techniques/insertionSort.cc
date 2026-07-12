//insertion sort, inserts element at correct order, keeps checking toward left(j--)
//TC : Best case O(n), worst case & avg case O(n^2)
class Solution {
public:
    vector<int> sortArray(vector<int>& arr) 
    {
        int n = arr.size();
        int i,j;
        for(int i=0;i<n;i++)
        {
            j = i;
            while(j > 0 && arr[j-1] > arr[j])
            {
                swap(arr[j],arr[j-1]);
                j--;
            }
        }
        return arr;
    }
};
