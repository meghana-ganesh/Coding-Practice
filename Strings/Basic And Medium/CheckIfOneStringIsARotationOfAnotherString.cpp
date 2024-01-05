//Best Approach:Two Pointer,Passed on CodingNinjas with 77% efficiency
//TIME COMPLEXITY:O(L1)
//SPACE COMPLEXITY:O(L1) //STRING S = P + P
int isCyclicRotation(string &p, string &q) 
{
    // Write your code here
    string s = p + p;
    int i=0,j=0;
    int l1 = s.size();
    int l2 = q.size();
    if(p.size() != l2)
        return 0;
    while(i<=l1)
    {
        if(s[i] == q[j])
        {
            j++;
            i++;
            if(j==l2)
                return 1;
            continue;
        }
        if(s[i] != q[j] && j!=0)
        {
            j = 0;
            continue;
        }
        i++;
    }
    return 0;
}


//Passed on leetcode,better than 35%,49/50 testcases on CodingNinjas
//TIME COMPLEXITY:O(L1^2)
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
//TIME COMPLEXITY:O(L1^2) //L1 FOR SUBSTR FUNC & L1 FOR FOR LOOP
//SPACE COMPLEXITY:O(L1)
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
