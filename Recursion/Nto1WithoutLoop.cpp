void helper(int *count,int x,vector<int> &res)
{
    if(*count < 1)
        return;
    res.push_back(*count);
    (*count)--;
    helper(count,x,res);
}
vector<int> printNos(int x) 
{
    // Write Your Code Here
    int count = x;
    vector<int> res;
    helper(&count,x,res);
    return res;
}
