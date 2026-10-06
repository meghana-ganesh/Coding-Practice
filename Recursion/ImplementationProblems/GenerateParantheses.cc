//O(2^N)
class Solution {
public:
    void helper(int n,int open,int closed,string curr,vector<string> &ans)
    {
        if(curr.length() == 2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(open < n)
        {
            helper(n,open+1,closed,curr + "(",ans); 
        }
        if(closed < open)
        {
            helper(n,open,closed+1,curr + ")",ans);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> ans;
        helper(n,0,0,"",ans);
        return ans;
    }
};
