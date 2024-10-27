class Solution {
public:
int call(int i,int j,vector<int>&v,vector<vector<int>>&dp)
{
    if(i>j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int w=0;
    for(int k=i;k<=j;k++)
    {
        w=max(w,v[i-1]*v[k]*v[j+1]+call(i,k-1,v,dp)+call(k+1,j,v,dp));
    }
    return dp[i][j]=w;
}
    int maxCoins(vector<int>& v) 
    {
        int n=v.size();
        v.insert(v.begin(),1);
        v.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return call(1,n,v,dp);
        
    }
};