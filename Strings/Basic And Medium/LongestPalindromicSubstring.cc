//TIME COMPLEXITY:O(N^2),TWO POINTER,EFFICIENCY:71%
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        int start = 0, end = 1;
        int low, hi;
        for (int i = 0; i < n; i++) 
        {
            low = i - 1;
            hi = i;
            while (low >= 0 && hi < n && s[low] == s[hi])
            {
                if (hi - low + 1 > end)
                {
                    start = low;
                    end = hi - low + 1;
                }
                low--;
                hi++;
            }
            low = i - 1;
            hi = i + 1;
            while (low >= 0 && hi < n && s[low] == s[hi])
            {
                if (hi - low + 1 > end)
                {
                    start = low;
                    end = hi - low + 1;
                
                }
                low--;
                hi++;
            }
        }
        string ans;
        for(int i=start;i<start+end;i++)
        {
            ans += s[i];
        }
        return ans;
    }
};


//TIME COMPLEXITY:O(N^2),MATRIX APPROACH,EFFICIENCY:44%
class Solution {
public:
    string longestPalindrome(string str) 
    {
        int n = str.size();
        bool table[n][n];
        int maxLength = 1;
        memset(table,0,sizeof(table));
        for(int i=0;i<n;i++)
        {
            table[i][i] = true;
        }
        // Check for sub-string of length 2.
        int start = 0;
        for (int i = 0; i < n - 1;i++)
        {
            if (str[i] == str[i + 1])
            {
                table[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }
        //Check for sub-string with length greater than 2
        for(int k = 3;k <= n;k++)
        {
            for (int i = 0;i < n - k + 1;i++)
            {
                int j = i + k - 1;
                if (table[i + 1][j - 1] && str[i] == str[j])
                {
                    table[i][j] = true;
                    if (k > maxLength) 
                    {
                        start = i;
                        maxLength = k;
                    }
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
