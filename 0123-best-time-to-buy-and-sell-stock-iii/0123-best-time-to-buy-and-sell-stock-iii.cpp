class Solution {
    private:
    int call(int cr,int state,int k,vector<int> &p,int n,vector<vector<vector<int>>>&dp)
{
    if(cr>=n || k==0)
    return 0;
    
    if(dp[cr][state][k]!=-1)
    return dp[cr][state][k];
    int pf=0;
    // wanna 1 buy
    if(state==1)
    {
        pf=max(call(cr+1,0,k,p,n,dp)-p[cr],call(cr+1,1,k,p,n,dp));
    }
    else //sell
    {
        pf=max(call(cr+1,0,k,p,n,dp),call(cr+1,1,k-1,p,n,dp)+p[cr]);
    }
    return dp[cr][state][k]=pf;

}
public:

    int maxProfit(vector<int>& prices) {
        int k=2;
        int n=prices.size();
        // int profit=0;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return call(0,1,k,prices,n,dp);
    }
};
