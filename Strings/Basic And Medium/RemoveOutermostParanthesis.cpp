int maxDepth(string s) 
{
	// Write your code here.
	int count=0;
    int maxi=INT_MIN;
    for(int i=0;i<s.length();i++)
	{
        maxi=max(maxi,count);
        if((s[i]=='('))
		{
            count++;
        }
        else if(s[i]==')')
		{ 
            count--;
        }
    }
    return maxi;
}
