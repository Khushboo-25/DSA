class Solution {
public:
long long call(int i,int j,vector<int>&a,int &n,vector<int>&b,vector<vector<long long>>&dp)
{
    if(i>=4)
    {
        return 0;
    }
    if(j>=n)
    return -1e18;
    if(dp[i][j]!=-1e18)
    return dp[i][j];
    long long p1=1ll*a[i]*b[j]+call(i+1,j+1,a,n,b,dp);
    long long p2=call(i,j+1,a,n,b,dp);
    return dp[i][j]=max(p1,p2);

}
    long long maxScore(vector<int>& a, vector<int>& b) 
    {
        int n=b.size();
        vector<vector<long long>>dp(5,vector<long long>(n+1,-1e18));
        long long ans=call(0,0,a,n,b,dp);
        return ans;
        
    }
};