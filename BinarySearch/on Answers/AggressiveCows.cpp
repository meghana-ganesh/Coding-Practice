int possible(vector<int> &stalls,int k,int dist)
{
    int countcows = 1,last = stalls[0];
    for(int i=0;i<stalls.size();i++)
    {
        if(stalls[i]-last >= dist)
        {
            countcows++;
            last = stalls[i];
        }
        if(countcows >= k)
            return true;
    }
    return false;
}

int binary_search(vector<int> &stalls,int k,int l,int u)
{
    while(l<=u)
    {
        int mid = l + (u-l)/2;
        if(possible(stalls,k,mid))
            l = mid+1;
        else
            u = mid-1;
    }
    return u;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n = stalls.size();
    return binary_search(stalls,k,0,stalls[n-1]-stalls[0]);
}
