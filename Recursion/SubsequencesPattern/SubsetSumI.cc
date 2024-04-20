void helper(vector<int> &num,vector<int> &temp,int *sum,int i)
{
	if(i == num.size())
	{
		temp.push_back(*sum);
		return;
	}
	*sum += num[i];
	helper(num,temp,sum,i+1);
	*sum -= num[i];
	helper(num,temp,sum,i+1);
}
vector<int> subsetSum(vector<int> &num)
{
	// Write your code here.	
	// sort(num.begin(),num.end());
	vector<int> temp;
	int sum = 0;
	helper(num,temp,&sum,0);
	sort(temp.begin(),temp.end());
	return temp;
}
