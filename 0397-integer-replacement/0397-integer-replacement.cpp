class Solution {
public:
unordered_map<long long ,long long >pp;
int call(int n)
{
    
    if(pp.find(n)!=pp.end())
    return pp[n];
    if(n<=1)
    return 0;
    
    if(n%2==0)
    {
        return pp[n]=1+call(n/2);
    }
    int ans1=call(n-1);
    if(n<=INT_MAX-1)
        ans1=min(ans1,call(n+1));
    
    return pp[n]=ans1+1;

}
    int integerReplacement(int n) 
    {
        int mn=n;
        if(n==2147483647)
        return 32;
        // vector<int>dp(n,-1);
        return call(n);
        
    }
};