void helper(int *count,int n,vector<string> &res)
{
	if(*count > n)
		return;
	res.push_back("Coding Ninjas");
	(*count)++;
	helper(count,n,res);
}
vector<string> printNTimes(int n) 
{
	// Write your code here.
	vector<string> res;
	int count = 1;
	helper(&count,n,res);
	return res;
}
