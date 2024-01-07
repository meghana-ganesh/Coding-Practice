//TIME COMPLEXITY:O(N+KLOGK) K-no. of unique characters in the string,n-m[s[i]]++ loop,in practice k<n so overall time complexity:O(N)
string sortByFrequency(int n, string& s)
{
	// Write Your Code here
	string ans = "";
	map<char,int> m1;
	for(int i=0;i<s.length();i++)
	{
		m1[s[i]]++;
	}
	for(auto it=m1.rbegin();it != m1.rend();it++)
	{
		for(int j=0;j<it->second;j++)
		{
			ans += it->first;
		}
	}
	return ans;
}
//use map because it is sorted based on order of keys and values,unordered map wont work as it is not sorted
