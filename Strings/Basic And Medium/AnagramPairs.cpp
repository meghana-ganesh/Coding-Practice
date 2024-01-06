//TIME COMPLEXITY:O(N) -using unordered map,extra space for unorderedmap
#include<bits/stdc++.h>
bool isAnagram(string str1, string str2)
{
    //Write your code here
    if(str1.size()!=str2.size())
        return 0;
    unordered_map<char,int>m1;
    for(int i=0;i<str1.size();i++)
    {
        m1[str1[i]]++;
    }
    for(int i=0;i<str2.size();i++)
    {
        m1[str2[i]]--;
    }
    for(int i=0;i<m1.size();i++)
    {
        if(m1[i]!=0)
            return false;
    }
    return true;
}

//TIME COMPLEXITY:O(NLOGN)-due to sorting,efficiency around 32%
#include<bits/stdc++.h>
bool isAnagram(string str1, string str2)
{
    //Write your code here
    int s1=str1.size(),s2=str2.size();
    if(s1!=s2)
        return 0;
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    for(int i=0;i<s1;i++)
    {
        if(str1[i]!=str2[i])
            return 0;
    }
    return 1;
    
}
