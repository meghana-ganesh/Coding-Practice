vector<int> getSecondOrderElements(int n, vector<int> a) 
{
    // Write your code here.
    int maxele = INT_MIN;
    int secmax = INT_MIN;
    int minele = INT_MAX;
    int secmin = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(a[i] >= maxele)
        {
            secmax = maxele;
            maxele = a[i];
        }
        else if(a[i] > secmax && a[i] != maxele)
            secmax = a[i];
        if(a[i] <= minele)
        {
            secmin = minele;
            minele = a[i];
        }
        else if(a[i] < secmin && a[i] != minele)
            secmin = a[i];
    }
    vector<int> res;
    res.push_back(secmax);
    res.push_back(secmin);
    return res;
}
//OR
vector<int> getSecondOrderElements(int n, vector<int> a) 
{
    // Write your code here.
    sort(a.begin(),a.end());
    vector<int> res;
    res.push_back(a[n-2]);
    res.push_back(a[1]);
    return res;
}
