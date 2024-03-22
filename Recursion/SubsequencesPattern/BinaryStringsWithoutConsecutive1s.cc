//TIME COMPLEXITY:O(2^N)
void helper(vector<string> &ans,string str,int N)
{
    if(N == 0)
    {
        ans.push_back(str);
        return;
    }
    if(str.back() == '0')
    {
        string str1 = str;
        str1.push_back('0');
        helper(ans,str1,N-1);
        string str2 = str;
        str2.push_back('1');
        helper(ans,str2,N-1);
    }
    else if(str.back() == '1')
    {
        string str3 = str;
        str3.push_back('0');
        helper(ans,str3,N-1);
    }
}
vector<string> generateString(int N)
{
    // Write your code here.
    vector<string> ans;
    string str1 = "0";
    helper(ans,str1,N-1);  //3
    string str2 = "1";
    helper(ans,str2,N-1);
    return ans;
}
//      0 N=4
//00 N=3
//000 N=2
//0000 N=1
//N = 0 0000
