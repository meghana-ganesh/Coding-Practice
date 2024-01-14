int countSubStrings(string str, int k) 
{
    // Write your code here.
    int n = str.length();
    int res = 0;
    for(int i=0;i<n;i++)
    {
        int cnt[26] = {0};
        int distinct_count = 0;
        for(int j=i;j<n;j++)
        {
            if(cnt[str[j]-'a'] == 0)
                distinct_count++;
            cnt[str[j]-'a']++;
            if(distinct_count == k)
                res++;
        }
    }
    return res;
}
