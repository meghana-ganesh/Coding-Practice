bool areIsomorphic(string &str1, string &str2)
{
    // Write your code here
    int l1 = str1.length();
    int l2 = str2.length();
    if(l1 != l2)
        return false;
    unordered_map<char,int>m1,m2;
    for(int i=0;i<l1;i++)
    {
        if(!m1[str1[i]] && !m2[str2[i]])
        {
            m1[str1[i]] = str2[i];
            m2[str2[i]] = str1[i];
        }
        else if(m1[str1[i]] != str2[i])
            return false;
    }
    return true;
}
//aab xxy
//m1[a] = x
//m2[x] = a
//m1[b] = y
//m2[y] = b
