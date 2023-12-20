int find_days(vector<int> &weights,int capacity)
{
    int days=1,load=0;
    for(int i=0;i<weights.size();i++)
    {
        if(load+weights[i] > capacity)
        {
            days++;
            load = weights[i];
        }
        else
            load += weights[i];
    }
    return days;
}

int binary_search(vector<int> &weights,int d,int l,int u)
{
    int ans = -1;
    while(l<=u)
    {
        int mid = l + (u-l)/2;
        int days = find_days(weights,mid);
        if(days <= d)
        {
            ans = mid;
            u = mid-1;
        }
        else if(days > d)
            l = mid+1;        
    }
    return ans;
}

int leastWeightCapacity(vector<int> &weights, int d)
{
    // Write your code here.
    int sum = 0;
    for(int i=0;i<weights.size();i++)
    {
        sum += weights[i];
    }
    return binary_search(weights,d,*max_element(weights.begin(),weights.end()),sum);
}
