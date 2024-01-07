int check(char a)
{
    if(a == 'I') 
        return 1;
    else if(a == 'V')
        return 5;
    else if(a == 'X')
        return 10;
    else if(a == 'L')
        return 50;
    else if(a == 'C')
        return 100;
    else if(a == 'D')
        return 500;
    else if(a == 'M')
        return 1000;
    else return 0;
}
int romanToInt(string s) 
{
    // Write your code here
    int ans = 0;
    for(int i = 0; i<s.length(); i++)
    {
        if(check(s[i]) >= check(s[i+1]))
            ans += (check(s[i]));
        else
            ans -= (check(s[i]));
    }
    return ans;
}
