//SEQUEL TO SUBSEQUENCEWITHSUMK.CC
//TC:O((2^N)*K) K IS THE SIZE OF THE ARRAY,ELIMINATES THE EXTRA SPACE OF USING ORDERED SET TO AVOID REPETITION
#include<algorithm>
void helper(vector<int> &arr,int n,int target,vector<int> &temp,int ind,vector<vector<int>> &ans)
{
	if(target == 0)
	{
		ans.push_back(temp);
		return;
	}
	for(int i=ind;i<arr.size();i++)
	{
		if(i > ind && arr[i] == arr[i-1])
			continue;
		if(arr[i] > target)
			break;
		temp.push_back(arr[i]);
		helper(arr,n,target-arr[i],temp,i+1,ans);
		temp.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>> ans;
	vector<int> temp;
	int ind = 0;
	helper(arr,n,target,temp,ind,ans);
	return ans;
}
