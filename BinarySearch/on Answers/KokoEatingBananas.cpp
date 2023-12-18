#include<bits/stdc++.h>
long long func(vector<int> v,int hourly)
{
    long long totalhrs = 0;
    for(int i=0;i<v.size();i++)
    {
        totalhrs += ceil((double)v[i]/(double)hourly);
    }
    return totalhrs;
}

int binary_search(vector<int> v,int h,int l,int u)
{
    while(l<=u)
    {
        int mid = l + (u-l)/2;
        long long totalhrs = func(v,mid);
        if(totalhrs > h)
            l = mid+1;
        else if(totalhrs <= h)
        {
            u = mid-1;
        }
    }
    return l;
}

int findMax(vector<int> v,int h)
{
    int maxele = INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        maxele = max(maxele,v[i]);
    }
    return maxele;
}


int minimumRateToEatBananas(vector<int> v, int h) 
{
    // Write Your Code Here
    return binary_search(v,h,1,findMax(v,h));
}
