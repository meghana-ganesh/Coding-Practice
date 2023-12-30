double median(vector<int>& a, vector<int>& b) 
{
	// Write your code here.
	int n1 = a.size();
	int n2 = b.size();
	if(n1>n2) return median(b,a);
	int n = n1 + n2;
	int left = (n1+n2+1)/2;
	int l=0,u=n1;
	while(l<=u)
	{
		int mid1 = l + (u-l)/2;
		int mid2 = left - mid1;
		int l1 = INT_MIN,l2 = INT_MIN;
		int r1 = INT_MAX,r2 = INT_MAX;
		if(mid1 < n1)
			r1 = a[mid1];
		if(mid2 < n2)
			r2 = b[mid2];
		if(mid1 - 1 >= 0)
		 	l1 = a[mid1-1];
		if(mid2 -1 >= 0)
			l2 = b[mid2-1];
		if(l1 <= r2 && l2 <= r1)
		{
			if(n % 2 == 1)
				return max(l1,l2);
			return (double)(max(l1,l2) + min(r1,r2))/2.0;
		}
		else if(l1 > r2)
			u = mid1-1;
		else
			l = mid1+1;
	}
	return -1;
}
