int isGood(int n,int digit,int sum)
{
	if(n == 0)
		return 1;
	int last = n % 10;
	if(last > sum && last != digit)
	{
		sum += last;
		return isGood(n/10,digit,sum);
	}
	else
		return 0;
}
vector<int> goodNumbers(int a, int b, int digit) 
{
	// Write your code here.
	vector<int> ans;
	for(int i=a;i<=b;i++)
	{
		if(i % 10 == digit)
			continue;
		if(isGood(i/10,digit,i%10))
			ans.push_back(i);
	}
	return ans;
}
//841
//841
//last = 4
//4 > 1
//sum = 5
//8,6,5
//8 > 5
