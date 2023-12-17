int func(int mid,int n,int m)
{
  long long ans = 1;
  for(int i=1;i<=n;i++)
  {
    ans *= mid;
    if(ans > m)
      return 2;
  }
  if(ans < m)
    return 1;
  return 0;
}

int binary_search(int n,int m,int l,int u)
{
  while(l<=u)
  {
    long long mid = l + (u-l)/2;
    int nthsquare = func(mid,n,m);
    if(nthsquare == 2)
      u = mid-1;
    else if(nthsquare == 1)
      l = mid+1;
    else if(nthsquare == 0)
      return mid;
  }
  return -1;
}

int NthRoot(int n, int m) 
{
  // Write your code here.
  return binary_search(n,m,1,m);
}
