//optimized:Swap func uses two-pointer approach(For built-in types, it uses efficient assembly instructions or memory copying techniques. 
//For user-defined types, 
//it leverages specialized template functions or the swap overload to provide efficient swapping mechanisms.)
#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
	int n = arr.size();
	int left = m + 1;
	int right = n - 1;
	while(left < right)
	{
		swap(arr[left],arr[right]);
		left++;
		right--;
	}
}
//1
//1 2 3 4 5 6

//my code:
#include <bits/stdc++.h> 
void reverseArray(vector<int> &arr , int m)
{
	// Write your code here.
	int n = arr.size();
	int left = m + 1;
	int right = n - 1;
	for(int i=left;i<right;i++)
	{
		int temp = arr[i];
		arr[i] = arr[right];
		arr[right] = temp;
		right--;
	}
}
