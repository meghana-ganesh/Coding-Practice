//hint: try right to left traversal instead of left to right so you can foresee elements to the right.
//TC: O(N)
//SC:O(k)

Solution {
  public:
    vector<int> leaders(vector<int>& arr) 
    {
        // code here
        int n = arr.size();
        vector<int> leaders;
        int i=n-1,j=n-1;
        while(j >= 0)
        {
            if(arr[j] >= arr[i])
            {
                leaders.push_back(arr[j]);
                i = j;
                j--;
            }
            else
            {
                j--;
            }
        }
        reverse(leaders.begin(),leaders.end());
        return leaders;
    }
};
