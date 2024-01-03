#include<bits/stdc++.h>
int maxele(vector<vector<int>> &g,int n,int mid)
{
    int maxe = -1;
    int maxi = -1;
    for(int i=0;i<n;i++)
    {
        if(g[i][mid] > maxe)
        {
            maxe = g[i][mid];
            maxi = i;
        }
    }
    return maxi;
}
vector<int> findPeakGrid(vector<vector<int>> &g)
{
    // Write your code here.
    int n = g.size();
    int m = g[0].size();
    int l=0,u=m-1;
    while(l<=u)
    {
        int mid = l + (u-l)/2;
        int row = maxele(g,n,mid);
        int left = mid-1 >= 0 ? g[row][mid-1] : -1;
        int right = mid+1 < m ? g[row][mid+1] : -1;
        if(g[row][mid] > left && g[row][mid] > right)
            return {row,mid};
        else if(g[row][mid] < left)
            u = mid-1;
        else
            l = mid+1;
    }
    return {-1,-1};
}
