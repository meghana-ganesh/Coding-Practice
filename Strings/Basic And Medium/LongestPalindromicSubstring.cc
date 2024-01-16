//TIME COMPLEXITY:O(N^2),MATRIX APPROACH



//TIME COMPLEXITY:O(N^3),TLE ON LEETCODE
class Solution {
public:
    string longestPalindrome(string str)
    {
        int n = str.size();
 
        // All substrings of length 1 are palindromes
        int maxLength = 1, start = 0;
    
        // Nested loop to mark start and end index
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = i; j < str.length(); j++)
            {
                int flag = 1;
                // Check palindrome
                for (int k = 0; k < (j - i + 1) / 2; k++)
                {
                    if (str[i + k] != str[j - k])
                        flag = 0;
                }
                // Palindrome
                if (flag && (j - i + 1) > maxLength) 
                {
                    start = i;
                    maxLength = j - i + 1;
                }
            }
        }
        string ans;
        for(int i=start;i<start+maxLength;i++)
        {
            ans += str[i];
        }
        return ans;
    }
};
