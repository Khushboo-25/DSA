class Solution {
public:
int call(int n, vector<int>&dp)
{
    if(n==2 || n==1)
    return 1;
    // if(n==3)
    // return 2;
    if(dp[n]!=-1)
    return dp[n];
    int s=1,e=n-1;
    int ans=n-1;
    while(s<=e)
    {
        int e1=call(e,dp);
        int s1=call(s,dp);
        ans=max({s*e,e1*s1,s*e1,s1*e,ans});
        s++;
        e--;
    }
    return dp[n]=ans;
    

}
    int integerBreak(int n) 
    {
        vector<int>dp(n+1,-1);
        return call(n,dp);
        
    }
};