class Solution {
public:

int call(int i,int &n,vector<int>&a,vector<int> &b,int vv,vector<vector<int>>&dp)
{
    if(i>=n)
    {
        return 0;
    }
    if(dp[i][vv]!=-1)
    return dp[i][vv];
    int ans=INT_MAX;
    for(int j=0;j<n;j++)
    {
        if(((vv>>j)&1)==0)
        {
            int v1=vv|(1<<j);
            ans= min(ans,(a[i]^b[j])+call(i+1,n,a,b,v1,dp));
        }
    }
    return dp[i][vv]=ans;
}
    int minimumXORSum(vector<int>& a, vector<int>& b) 
    {
        int n=a.size();
        int vv=0;
        vector<vector<int>>dp(n+1,vector<int>(1e6+1,-1));
        int ans=call(0,n,a,b,vv,dp);
        return ans;
        
    }
};