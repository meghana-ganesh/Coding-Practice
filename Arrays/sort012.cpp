#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int a0 = 0;
   int a1 = 0;
   int a2 = n-1;
   while(a1 <= a2)
   {
      if(arr[a1] == 1)
         a1++;
      else if(arr[a1] == 0)
      {
         swap(arr[a1],arr[a0]);
         a0++;
         a1++;
      }
      else if(arr[a1] == 2)
      {
         swap(arr[a1],arr[a2]);
         a2--;
      }
   }
}
//1 1 1 0 0 2 2
