//TC: O(N)
class Solution {
  public:
    int getSecondLargest(vector<int> &arr) 
    {
        // code here
        int n = arr.size();
        int max = INT_MIN;
        int secondmax = INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(arr[i] > max)
            {
                secondmax = max;
                max = arr[i];
            }
            if(arr[i] > secondmax && arr[i] != max)
                secondmax = arr[i];
        }
        return secondmax;
    }
};
