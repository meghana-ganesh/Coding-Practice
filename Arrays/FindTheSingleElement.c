#include<vector>

int getSingleElement(vector<int> &arr){
	// Write your code here.
	int i=0;
	while(i <= arr.size())
	{
		if(arr[i] == arr[i+1])
		{
			i = i + 2;
		}
		else
			return arr[i];
	}
}
