class Solution {
public:
int call(int cr,int state,int k,vector<int> &p,int &n,vector<vector<vector<int>>>&dp)
{
    if(cr>=n || k==0)
    return 0;
    int pf=0;
    if(dp[cr][k][state]!=-1)
    return dp[cr][k][state];
    // wanna 1 buy
    if(state==1)
    {
        pf=max({pf,call(cr+1,0,k,p,n,dp)-p[cr],call(cr+1,1,k,p,n,dp)});
    }
    else //sell
    {
        pf=max({pf,call(cr+1,0,k,p,n,dp),call(cr+1,1,k-1,p,n,dp)+p[cr]});
    }
    return dp[cr][k][state]=pf;

}
    int maxProfit(int k, vector<int>& prices) 
    {
        int n=prices.size();
        // int profit=0;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(3,-1)));
        return call(0,1,k,prices,n,dp);
        
    }
};