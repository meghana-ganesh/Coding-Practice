//TIME COMPLEXITY:O(2^N)

bool findSubset(int i,int sum,int k, vector<int> a) 
{
    if(sum>k) 
        return false;
    if(i==a.size())
    {
        if(sum==k) 
            return true;
        return false;
    }
    return (findSubset(i+1,sum,k,a)||findSubset(i+1,sum+a[i],k,a));
}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    return findSubset(0,0,k,a);

}
