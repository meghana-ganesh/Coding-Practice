#include <cstring>
int helper(string &str,int start,int end)
{
    if(start <= end)
    {
        if(str[start] == str[end])
            return helper(str,start+1,end-1);
        else
            return -1;
    }
}
bool isPalindrome(string& str) 
{
    // Write your code here.
    int start = 0,end = str.length() - 1;
    if(helper(str,start,end) == -1)
        return false;
    else
        return true;
}
