int traffic(int n, int m, vector<int> vehicle)
{
	// Write your code here.
	int e=0,s=0,maxlen=INT_MIN;
	while(e != n)
	{
		if(m != 0 && vehicle[e] == 0)
		{
			m--;
			e++;
		}
		else if(vehicle[e] == 1)
			e++;
		else if(m == 0 && vehicle[e] == 0)
		{
			if(vehicle[s] == 0)
			{
				m++; //releasing one zero on sliding
			}
			s++;
		}
		maxlen = max(maxlen,(e-s));
	}
	return maxlen;
}
//8 3
//0 1 0 0 1 0 1 0
//m=2,e=1
//maxlen = 1
//m=2,e=2
//maxlen = max(1,2) = 2
//m = 1,e = 3
//maxlen = 2
//m=0,e=4
//maxlen=4
//e=5
//maxlen = 5

//m=0,v[e]=0 m=1,s=1
//maxlen = 4
//
