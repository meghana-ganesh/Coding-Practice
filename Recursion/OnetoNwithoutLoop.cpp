#include <vector>

std::vector<int> res;
void helper(int *count,int x,vector<int> &res)
{
    if(*count > x)
        return;
    res.push_back(*count);
    (*count)++;
    helper(count,x,res);
}
vector<int> printNos(int x) 
{
    // Write Your Code Here
    vector<int> res;
    int count = 1;
    helper(&count,x,res);
    return res;
}
