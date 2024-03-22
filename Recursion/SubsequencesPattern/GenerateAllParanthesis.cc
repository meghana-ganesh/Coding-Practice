//TIME COMPLEXITY:O(2^N)
void helper(vector<string> &ans,string str,int open,int close)
{
    if(open==0 && close == 0)
    {
        ans.push_back(str);
        return;
    }
    if(open != 0)
    {
        string str1 = str;
        str1.push_back('(');
        helper(ans,str1,open-1,close);
    }
    if(close>open)
    {
        string str2 = str;
        str2.push_back(')');
        helper(ans,str2,open,close-1);
    }
}
vector<string> validParenthesis(int n)
{
    // Write your code here.
    vector<string> ans;
    string str = "";
    int open = n,close = n;
    helper(ans,str,open,close);
    return ans;
}
//          open + close
//P(N) = P(N-1)+P(N-1) = 2P(N-1) = 2*2*P(N-2) = 2^N
//.                                 
//.
//P(1) = P(0)+P(0) = 1
