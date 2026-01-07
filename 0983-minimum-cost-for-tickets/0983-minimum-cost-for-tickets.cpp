class Solution {
public:
int call(int sv,int i,vector<int>&days,vector<int>&costs,int &n,vector<vector<int>>&dp)
{
    if(i>=n)
    return 0;
    if(dp[sv][i]!=-1)
    return dp[sv][i];
    int ans=INT_MAX;
    if(sv<days[i]) // must
    {
        ans=min(ans,costs[0]+call(days[i],i+1,days,costs,n,dp));
        ans=min(ans,costs[1]+call(days[i]+6,i+1,days,costs,n,dp));
        ans=min(ans,costs[2]+call(days[i]+29,i+1,days,costs,n,dp));
    }
    else //(sv>=i)
    {
        ans=min(ans,costs[0]+call(days[i],i+1,days,costs,n,dp));
        ans=min(ans,costs[1]+call(days[i]+6,i+1,days,costs,n,dp));
        ans=min(ans,costs[2]+call(days[i]+29,i+1,days,costs,n,dp));
        ans=min(ans,call(sv,i+1,days,costs,n,dp));
    }
    return dp[sv][i]=ans;
}
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        int n=days.size();
        vector<vector<int>>dp(400,vector<int>(400,-1));
        return call(0,0,days,costs,n,dp);
    }
};