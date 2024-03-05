//TIME COMPLEXITY:O(N^2)
//O(N) for insertatpos() and O(N) for sort() called for every element
#include <bits/stdc++.h> 

void insertatpos(stack<int>&s,int ele)
{
	if(s.empty())
	{
		s.push(ele);
		return;
	}
	if(ele < s.top())
	{
		int top = s.top();
		s.pop();
		insertatpos(s,ele);
		s.push(top);
	}
	else
		s.push(ele);
}
void sort(stack<int>&s)
{
	if(s.empty())
		return;
	int ele = s.top();
	s.pop();
	sort(s);
	insertatpos(s,ele);
}
stack<int> sortStack(stack<int> &s)
{
	// Write code here.
	sort(s);
	return s;
}
//2 1 9 3

//ele = 3
//2 1 9
//

//ele = 9
//2 1

//ele = 1
//2

//ele = 2
//
//insertatpos(s,ele)
//2
//1,2
//1,2,9
//1 2 3 9
//1 2 3 9
