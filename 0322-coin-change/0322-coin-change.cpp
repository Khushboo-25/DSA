class Solution {
public:
// int MOD=1e9+7;
int call(int i,int csum,int &sum,int &n,vector<int> &a,vector<vector<int>>&dp)
{
    if(csum==sum)
    return 0;
    
    if(i>=n || csum>sum)
    return INT_MAX;
    
    if(dp[i][csum]!=-1)
    return dp[i][csum];
    int ways=INT_MAX;
    if(a[i]<=sum-csum)
    {
        int take=call(i,csum+a[i],sum,n,a,dp);
        if(take!=INT_MAX)
        ways=min(take+1,ways);
    }

    int nottake=call(i+1,csum,sum,n,a,dp);
    ways=min(nottake,ways);
    return dp[i][csum]=ways;
}
    int coinChange(vector<int>& a, int sum) {
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int ways=call(0,0,sum,n,a,dp);
        
        return ways==INT_MAX?-1:ways;
    }
};