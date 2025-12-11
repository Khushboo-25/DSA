class Solution {
public:
int call(int i,int tm,vector<int> &st,int &n,vector<vector<int>>&dp)
{
    if(i>=n)
    {
        return 0;
    }
    if(dp[i][tm]!=-1)
    return dp[i][tm];
    
    int take=tm*st[i]+call(i+1,tm+1,st,n,dp);
    int nottake=call(i+1,tm,st,n,dp);
    return dp[i][tm]=max(take,nottake);
}
    int maxSatisfaction(vector<int>&st)
    {
        int n=st.size();
        sort(st.begin(),st.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return call(0,1,st,n,dp);
    }
};