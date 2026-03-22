class Solution {
public:
int call(int i,int am,int &n,vector<int>&c,vector<vector<int>>&dp)
{
    if(i>=n)
    {
        if(am==0)
        return 0;
        return -1;

    }
    if(dp[i][am]!=INT_MIN)
    return dp[i][am];
    int ans=INT_MAX;
    if(am-c[i]>=0)
    {
        int ans1=call(i,am-c[i],n,c,dp);
        if(ans1>=0)
        ans=min(ans,1+ans1);
        int ans2=call(i+1,am-c[i],n,c,dp);
        if(ans2>=0)
        ans=min(ans,1+ans2);
    }
    int ans3=call(i+1,am,n,c,dp);
    if(ans3>=0)
    ans=min(ans,ans3);
    if(ans==INT_MAX)
    return dp[i][am]=-1;
    return dp[i][am]=ans;
}
    int coinChange(vector<int>&c, int am) 
    {
        int n=c.size();
        vector<vector<int>>dp(n+1,vector<int>(am+1,INT_MIN));
        return call(0,am,n,c,dp);
        
    }
};