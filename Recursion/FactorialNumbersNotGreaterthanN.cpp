long long factorial(long long n)
{
    if(n == 1)
        return 1;
    return n*factorial(n-1);
}
vector<long long> factorialNumbers(long long n) 
{
    // Write Your Code Here
    vector<long long> res;
    long long i=1,ans;
    while(i<=n)
    {
        ans = factorial(i);
        if(ans <= n)
            res.push_back(ans);
        else
            break;
        i++;
    }

    return res;
}
