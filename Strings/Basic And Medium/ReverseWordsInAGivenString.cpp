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
