//TC:O(2^N)
void helper(vector<string> &ans,string s,string str,int N)
{
    if(N == s.length())
    {
        ans.push_back(str);
        return;
    }
    string str1 = str;
    str1.push_back(s[N]);
    helper(ans,s,str1,N+1);
    string str2 = str;
    helper(ans,s,str2,N+1);
}
//2 abc
//a //ab //abc
//"" //b //

vector<string> generateSubsequences(string s)
{
    // Write your code here.
    vector<string> ans;
    string str = "";
    int N = 0;
    helper(ans,s,str,N);
    return ans;
}
