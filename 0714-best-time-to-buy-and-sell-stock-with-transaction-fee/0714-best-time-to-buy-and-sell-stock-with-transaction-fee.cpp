class Solution {
public:
int call(int op,int i,int &fee,int &n,vector<int>&pr,vector<vector<int>>&dp)
{
    if(i>=n)
    return 0;
    if(dp[op][i]!=-1)
    return dp[op][i];
    int ans=0;
    if(op==1)
    {
        ans=max(ans,call(0,i+1,fee,n,pr,dp)-pr[i]-fee);
        ans=max(ans,call(1,i+1,fee,n,pr,dp));
    }
    else
    {
        ans=max(ans,call(1,i+1,fee,n,pr,dp)+pr[i]);
        ans=max(ans,call(0,i+1,fee,n,pr,dp));
    }
    return dp[op][i]=ans;
}
    int maxProfit(vector<int>& pr, int fee) 
    {
        int n=pr.size();
        vector<vector<int>>dp(2,vector<int>(n+1,-1));
        return call(1,0,fee,n,pr,dp);
        
    }
};