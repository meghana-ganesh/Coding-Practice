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
