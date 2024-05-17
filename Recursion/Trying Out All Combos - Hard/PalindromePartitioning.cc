//TIME COMPLEXITY: O( (2^n) *k*(n/2) )
//Reason: O(2^n) to generate every substring and O(n/2)  to check if the substring generated is a palindrome. 
//O(k) is for inserting the palindromes in another data structure, where k  is the average length of the palindrome list.


//SPACE COMPLEXITY: O(k * x)
//Reason: The space complexity can vary depending upon the length of the answer. 
//k is the average length of the list of palindromes and if we have x such list of palindromes in our final answer. 
//The depth of the recursion tree is n, so the auxiliary space required is equal to the O(n).
class Solution {
public:
    int isPalindrome(string s)
    {
        for(int i=0;i<s.size()/2;i++)
        {
            if(s[i] != s[s.size()-i-1])
            {
                return 0;
            }
        }
        return 1;
    }
    //a
    //aabb
    //aaabb
    void helper(string s,int ind,int n,vector<vector<string>> &ans,vector<string> &temp)
    {
        if(ind == n)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            if(isPalindrome(s.substr(ind,i-ind+1))) //substr(start,length of substr to be extracted)
            {
                temp.push_back(s.substr(ind,i-ind+1));
                helper(s,i+1,n,ans,temp);
                temp.pop_back(); //remember why this is done
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;
        helper(s,0,s.size(),ans,temp);
        return ans;
    }
};
//aabb
