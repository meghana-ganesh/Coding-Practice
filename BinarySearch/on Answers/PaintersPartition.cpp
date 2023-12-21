int count_painters(vector<int> &boards,int k,int maxtime)
{
    int painter=1,sum=0;
    for(int i=0;i<boards.size();i++)
    {
        if(sum + boards[i] <= maxtime)
            sum += boards[i];
        else
        {
            painter++;
            sum = boards[i];
        }
    }
    return painter;
}

int binary_search(vector<int> &boards,int k,int l,int u)
{
    while(l<=u)
    {
        int mid = l + (u-l)/2;
        int noofpainters = count_painters(boards,k,mid);
        if(noofpainters > k)
            l = mid+1;
        else if(noofpainters <= k)
            u = mid-1;
    }
    return l;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int sum = 0;
    for(int i=0;i<boards.size();i++)
    {
        sum += boards[i];
    }
    return binary_search(boards,k,*max_element(boards.begin(),boards.end()),sum);
}
