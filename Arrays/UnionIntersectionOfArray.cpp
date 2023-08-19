#include <bits/stdc++.h> 
#include<utility>
pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
	// Write Your Code here.  
	pair <int,int>p{0,m+n};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(arr1[i] == arr2[j])
			{
				p.first++;
				p.second--;
			}
		}
	}
	return p;	
}
