#include<set>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void helper(set<vector<int>> &ans,vector<int> a,vector<int> temp,long long k,int sum,int N)
{
    if(sum == k)
    {
        sort(temp.begin(),temp.end());
        ans.insert(temp);
        return;
    }
    if(sum > k || N == a.size())
        return;
    sum += a[N];
    vector<int> temp1 = temp;
    temp1.push_back(a[N]);
    helper(ans,a,temp1,k,sum,N+1);
    sum -= a[N];
    helper(ans,a,temp,k,sum,N+1);
}
//1 2 3 1 1 1
//1 2
//1 1 1
//2 1
void subsequenceWithSumK(vector<int> a, long long k) 
{
    // Write your code here
    set<vector<int>> ans;
    int N = 0;
    int sum = 0;
    vector<int> temp;
    helper(ans,a,temp,k,sum,N);
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        for(int j=0;j<(*i).size();j++)
        {
            cout << (*i)[j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    vector<vector<int>> res;
    vector<int> a = {1,2,3,1,1,1};
    subsequenceWithSumK(a,3);
}
