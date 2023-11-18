//TIME COMPLEXITY:O(N)
//SPACE COMPLEXITY:O(N+M) = O(MAX(M,N))

vector < int > sortedArray(vector < int > a, vector < int > b) 
{
    // Write your code here
    int i=0,j=0;
    vector<int> ans;
    while(i<a.size() && j<b.size())
    {
        if(a[i] <= b[j])
        {
            if(ans.size()==0 || ans.back() != a[i])
                ans.push_back(a[i]);
            i++;
        }
        else if(b[j] < a[i])
        {
            if(ans.size() == 0 || ans.back() != b[j])
                ans.push_back(b[j]);
            j++;
            
        }
    }
    while (i < a.size()) 
    {
        if(ans.size()==0 || ans.back() != a[i])
            ans.push_back(a[i]);
        i++;
    }

    while (j < b.size()) 
    {
        if(ans.size() == 0 || ans.back() != b[j])
            ans.push_back(b[j]);
        j++;
    }
    return ans;
}

//USING SET
//TIME COMPLEXITY:O(N+M)
#include<bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) 
{
    // Write your code here
    set<int> st;
    for(auto i:a)
        st.insert(i);
    for(auto i:b)
        st.insert(i);
    vector<int> v;
    for(auto i:st)
        v.push_back(i);
    return v;
}
