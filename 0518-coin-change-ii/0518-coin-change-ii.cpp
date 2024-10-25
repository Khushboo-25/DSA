class Solution {
public:
// int MOD=1e9+7;
int call(int i,int csum,int n,int sum,vector<int> &a,vector<vector<int>>&dp)
{
    if(csum==sum)
    return 1;
    
    if(i>=n || csum>sum)
    return 0;
    
    if(dp[i][csum]!=-1)
    return dp[i][csum];
    int ways=0;
    if(a[i]<=sum-csum)
    {
        ways=(call(i,csum+a[i],n,sum,a,dp)+call(i+1,csum,n,sum,a,dp));
    }
    else
    {
        ways=call(i+1,csum,n,sum,a,dp);
    }
    return dp[i][sum]=ways;
}

    int change(int sum, vector<int>& a) {

        int n=a.size();
         vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return call(0,0,n,sum,a,dp);
    }
};