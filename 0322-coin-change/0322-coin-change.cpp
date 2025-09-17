class Solution {
public:
int call(int i,int tt,vector<int> &c,int &n,vector<vector<int>>&dp)
{
    if(i>=n)
    {
        if(tt==0)
        {
            return 0;
        }
        return 1e5;
    }
    if(dp[i][tt]!=-1)
    return dp[i][tt];
    int ans=1e5;
    if(c[i]<=tt)
    {
        ans=min(1+call(i+1,tt-c[i],c,n,dp),ans);
        ans=min(1+call(i,tt-c[i],c,n,dp),ans);
    }
    ans=min(ans,call(i+1,tt,c,n,dp));
    return dp[i][tt]=ans;

}
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=call(0,amount,coins,n,dp);
        if(ans>1e4)
        return -1;
        return ans;
        
    }
};