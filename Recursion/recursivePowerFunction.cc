double myPow(double x, int n)
{
    // Write Your Code Here
    if(n == 0)
        return double(1);
    else if(n<0)
    {
        x = 1/x;
        n = -n;
    }
    return x*myPow(x,n-1);
}
//2,4
//n = 4
//2,3 = 2*8 = 16
//n = 3
//2*2,2 = 2*4
//n = 2
//2*2,1 = 2*2
//n = 1
//2*2,0 = 2*1
//n = 0
//return 1


//n<0
//2^-3
//n = 3
//1/2*pow(1/2,2)
//n = 2
//1/2*pow(1/2,1) = 1
//n = 1
//1/2*pow(1/2,0) = 1/2
//n = 0
//return 1
