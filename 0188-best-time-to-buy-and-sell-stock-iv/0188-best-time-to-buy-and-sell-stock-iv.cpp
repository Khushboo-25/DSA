class Solution {
public:
int call(int op,int i,int k,int &n,vector<int>&pr,vector<vector<vector<int>>>&dp)
{
    if(i>=n)
    return 0;
    if(dp[op][i][k]!=-1)
    return dp[op][i][k];
    int ans=0;
    // wannna buy
    if(k>0 && op==1)
    {
        ans=max(ans,call(0,i+1,k,n,pr,dp)-pr[i]);
        ans=max(ans,call(1,i+1,k,n,pr,dp));
    }
    if(k>0 && op==0)
    {
        ans=max(ans,call(1,i+1,k-1,n,pr,dp)+pr[i]);
        ans=max(ans,call(0,i+1,k,n,pr,dp));
    }
    return dp[op][i][k]=ans;
    
}
    int maxProfit(int k, vector<int>& pr) 
    {
        int n=pr.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return call(1,0,k,n,pr,dp);
        
    }
};