class Solution {
public:
int call(int i,int sum,int &n,vector<int>&cn,vector<vector<int>>&dp)
{
    if(sum==0)
    return 1;
    if(i>=n)
    return 0;
    if(dp[i][sum]!=-1)
    return dp[i][sum];
    int ans=0;
    if(cn[i]<=sum)
    {
        ans+=call(i,sum-cn[i],n,cn,dp);//  not moved
    }
    ans+=call(i+1,sum,n,cn,dp); // moved
    return dp[i][sum]=ans;
}
    int change(int sum, vector<int>& cn) 
    {
        int n=cn.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return call(0,sum,n,cn,dp);

        
    }
};