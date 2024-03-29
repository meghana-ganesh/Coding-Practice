//TIME COMPLEXITY:O(2^N)
void helper(vector<int> &ARR,int B,int N,vector<vector<int>> &ans,vector<int> temp)
{
    if(N == ARR.size())
    {
        if(B == 0)
        {
            ans.push_back(temp);
        }
        return;
    }
    if(ARR[N] <= B)
    {
        temp.push_back(ARR[N]);
        helper(ARR,B-ARR[N],N,ans,temp);
        temp.pop_back();
    }
    helper(ARR,B,N+1,ans,temp);  
}
vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    // Write your code here.
    vector<int> temp;
    vector<vector<int>> ans;
    sort(ARR.begin(),ARR.end());
    helper(ARR,B,0,ans,temp);
    return ans;
}
