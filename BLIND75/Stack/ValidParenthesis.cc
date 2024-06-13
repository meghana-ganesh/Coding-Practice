//TC:O(N)
#include<stack>
class Solution {
public:
    bool isValid(string s) 
    {
        stack<int> st;
        unordered_map<char,char> mpp = {{')','('},{'}','{'},{']','['}};
        int i = 0;
        while(i < s.size())
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else
            {
                if(!st.empty())
                {
                    char c = st.top();
                    if(c != mpp[s[i]])
                        return false;
                    st.pop();
                }
                else              //if stack is empty here it means only closing brackets are left
                    return false;
            }
            i++;
        }
        if(!st.empty())   //unbalanced opening brackets
            return false;
        return true;
    }
};
