class Solution {
public:
long long lcm(long long a,long long b)
{
    return (a*1ll*b)/__gcd(a,b);
}
bool check(long long lmt, int &a,int &b,int &c,int &n)
{
    long long na=lmt/a;
    long long  nb=lmt/b;
    long long  nc=lmt/c;
    long long  nab=lmt/(lcm(a*1ll,b*1ll));
    long long  nbc=lmt/(lcm(b*1ll,c*1ll));
    long long nca=lmt/(lcm(c*1ll,a*1ll));
    long long nabc=lmt/lcm(lcm(a*1ll,b*1ll),c*1ll);
    long long p=na+nb+nc-nbc-nca-nab+nabc;
    if(p>=n)
    return 1;
    return 0;
}
    int nthUglyNumber(int n, int a, int b, int c) 
    {
         int ans=INT_MAX;
         
        int s=1,e=2e9+1;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(check(m,a,b,c,n))
            {
                ans=m;
                e=m-1;
            }
            else
            {
                s=m+1;
            }

        }
        return ans;
    }
};