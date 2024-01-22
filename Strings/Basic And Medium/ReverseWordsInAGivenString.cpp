//CODINGNINJAS ALL TESTCASES PASSED IN REVERSEWORDS(MODERATE),BUT 1 TESTCASE NOT PASSED IN REVERSEWORDSINASTRING(EASY)
int n = str.length();
    string word = "";
    string rev = "";
    int l = 0;
    while(str[l] == ' ')
    {
        l++;
    }
    int t = n-1;
    while(str[t] == ' ')
    {
        t--;
    }
    for(int i=l;i<t+1;i++)
    {
        if(str[i] == ' ')
        {
            while(i<t+1 && str[i] == ' ')
            {
                i++;
            }
            i--;
            if(word != "")
                rev = word + rev;
            rev = str[i] + rev;
            word = "";
        }
        else
            word += str[i];
    }
    if(word != "")
    {
        rev = word + rev;
    }
    return rev;

//ACCEPTED BY LEETCODE BUT TLE IN CODING NINJAS
//TIME COMPLEXITY:O(N) SPACE COMPLEXITY:O(1)
string reverseString(string &str)
{
	// Write your code here.	
	string temp = "";
	string ans = "";
    int n = str.length();
	for(int i=0;i<n;i++)
	{
		if(str[i] != ' ')
			temp += str[i];
		else if(str[i] == ' ')
		{
			if(i+1 < n && str[i+1] == ' ')
				continue;
			if(ans != "")
				ans = temp + " " + ans;
			else
				ans = temp;
			temp = "";
		}
	}
	if(str[n-1] != ' ')
        if(ans != "")
		    ans = temp + " " + ans;
        else
            ans = temp;
	return ans;
}


//TIME COMPLEXITY:O(N) SPACE COMPLEXITY:O(N) - STACK+ANS
#include<stack>
string reverseString(string &str)
{
	// Write your code here.
	int n = str.length();
	stack<string> stack;
	string temp = "";
	for(int i=0;i<n;i++)
	{
		if(str[i]!= ' ')
			temp += str[i];
		if(str[i] == ' ' && temp != "")
		{
			stack.push(temp);
			temp = "";
		}
	}
	if(temp != "")
		stack.push(temp);
	temp = "";
	while(!stack.empty())
	{
		temp += stack.top();
		temp += " ";
		stack.pop();
	}
	return temp;
}
//hi how are you
//you are
