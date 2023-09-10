//O(2*N) APPROACH:
#include <bits/stdc++.h> 
int uniqueSubstrings(string str)
{
    //Write your code here
    int l = 0,r = 0;
    int n = str.size();
    int max_ans = INT_MIN;
    int isrepeated = 0;
    unordered_set<char> set;
    for(int r=0;r<n;r++)
    {
        if(set.find(str[r]) != set.end())
        {
            while(l<r && set.find(str[r]) != set.end())
            {
                isrepeated = 1;
                set.erase(str[l]);
                l++;
            }
        }
        set.insert(str[r]);
        max_ans = max(max_ans,r-l+1);        
    }
    if(isrepeated == 0)
        return n;
    else
        return max_ans;
    
}


//O(N^2) APPROACH:
#include <bits/stdc++.h> 
int uniqueSubstrings(string str)
{
    //Write your code here
    int n = str.size();
    if(n == 0)
        return 0;
    int max_ans =  INT_MIN;
    int isrepeating = 0;
    for(int i=0;i<n;i++)
    {
        unordered_set<char> set;
        for(int j=i;j<n;j++)
        {
            if(set.find(str[j]) != set.end())
            {
                isrepeating = 1;
                max_ans = max(max_ans,j-i);
                break;
            }
            set.insert(str[j]);
        }
    }
    if(isrepeating == 0)
        return n;
    return max_ans;
}
