class Solution {
public:
int mod=1e9+7;
int call(int l1,int l2,int i,int &n,vector<int>&a,vector<vector<vector<int>>>&dp)
{
    if(i>=n)
    {
        if(l2==-1)
        return 0;
        return 1;
    }
    if(dp[l1+1][l2+1][i]!=-1)
    return dp[l1+1][l2+1][i];
    int ans=0;

    if(a[i]%2==0)
    {
        if(!(l1==0 && l2==0))
        ans=(ans+(call(l2,0,i+1,n,a,dp))%mod)%mod;
    }
    else
    {
        if(!(l1==1 && l2==1))
        ans=(ans+(call(l2,1,i+1,n,a,dp))%mod)%mod;
    }
    ans=(ans+(call(l1,l2,i+1,n,a,dp))%mod)%mod;
    return dp[l1+1][l2+1][i]=ans;
}
    int countStableSubsequences(vector<int>&a) 
    {
        int n=a.size();
        vector<vector<vector<int>>>dp(3,vector<vector<int>>(3,vector<int>(n+1,-1)));
        return call(-1,-1,0,n,a,dp);
    }
};