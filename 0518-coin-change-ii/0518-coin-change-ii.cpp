class Solution {
public:
// int MOD=1e9+7;
int call(int i,int sum,int &n,vector<int> &a,vector<vector<int>>&dp)
{
    if(sum==0)
    return 1;
    
    if(i>=n )
    return 0;
    
    if(dp[i][sum]!=-1)
    return dp[i][sum];
    int ways=0;
    if(a[i]<=sum)
    {
        int take=call(i,sum-a[i],n,a,dp);
        ways=take+ways;
    }

    int nottake=call(i+1,sum,n,a,dp);
    ways=nottake+ways;
    return dp[i][sum]=ways;
}
    int change(int sum, vector<int>& a) {

        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int ways=call(0,sum,n,a,dp);
        
        return ways;
    }
};