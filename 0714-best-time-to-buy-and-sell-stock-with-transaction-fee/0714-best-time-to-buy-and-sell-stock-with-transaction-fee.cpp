class Solution {
public:
int call(int in,int state,vector<int> &p,int &n,vector<vector<int>>&dp,int &fee)
{
    if(in>=n)
    return 0;
    if(dp[in][state]!=-1)
    return dp[in][state];
    //wanna buy
    int pf=0;
    if(state==1)
    {
        // if(k>1)
        int pf1=call(in+1,0,p,n,dp,fee)-p[in];
        int pf2=call(in+1,1,p,n,dp,fee);
        pf=max(pf,max(pf1,pf2));
    }
    else // wanna sell
    {
        int pf1=call(in+1,0,p,n,dp,fee);
        int pf2=call(in+1,1,p,n,dp,fee)+p[in]-fee;
        pf=max(pf,max(pf1,pf2));
    }
    return dp[in][state]=pf;
}
    int maxProfit(vector<int>& prices, int fee) 
    {
    
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return call(0,1,prices,n,dp,fee);
        
    }
};