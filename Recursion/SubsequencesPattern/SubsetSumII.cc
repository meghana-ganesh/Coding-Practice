void helper(vector<int> &arr,vector<vector<int>> &result,vector<int> &temp,int ind)
{
    result.push_back(temp);
    for(int i=ind;i<arr.size();i++)
    {
        if(i != ind && arr[i] == arr[i-1])
            continue;
        temp.push_back(arr[i]);
        helper(arr,result,temp,i+1);
        temp.pop_back();
    }
}
//1 2 2 2 3 4 5
vector<vector<int>> getUniqueSubsets(vector<int>& arr) 
{
    // Write Your Code Here 
    vector<vector<int>> result;   
    vector<int> temp;
    helper(arr,result,temp,0);
    return result;
}
