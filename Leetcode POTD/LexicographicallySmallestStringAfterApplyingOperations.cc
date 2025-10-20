class Solution {
public:
    string addToOddIndex(string s, int a)
    {
        for(int i=1;i<s.size();i+=2)
        {
            s[i] = (((s[i] - '0') + a) % 10 ) + '0';
        }
        return s;
    }
    string rotateToRight(string s, int b)
    {
        b = b % s.size();
        reverse(s.begin(),s.end());
        reverse(s.begin(),s.begin()+b);
        reverse(s.begin()+b,s.end());
        return s;
    }
    void dfs(string s, unordered_set<string> &vis,string &ans,int a,int b)
    {
        if(vis.count(s))
            return;
        vis.insert(s);
        ans = min(ans,s);
        dfs(addToOddIndex(s,a),vis,ans,a,b);
        dfs(rotateToRight(s,b),vis,ans,a,b);
    }
    string findLexSmallestString(string s, int a, int b) 
    {
        unordered_set<string> vis;
        string ans = s;
        dfs(s,vis,ans,a,b);
        return ans;
    }
};
