//Passed on leetcode,better than 35%,49/50 testcases on CodingNinjas
class Solution {
public:
    bool rotateString(string p, string q) 
    {
        if(p.length() != q.length())
            return false;
        string concatp = p + p;
        if(concatp.find(q) != string::npos)
            return true;
        return false;
    }
};

//Passed on Leetcode,better than 7%,44/50 testcases on CodingNinjas
int isCyclicRotation(string &p, string &q) 
{
    // Write your code here
    int l1 = p.length();
    int l2 = q.length();
    if(l1 != l2)
        return false;
    for(int i=l1;i>=0;i--)
    {
        if(p == q)
            return 1;
        p = p[l1-1] + p.substr(0,l1-1);
    }
    return 0;
}
