class Solution {
public:
int call(int i,int j,int&n,int&m,vector<int>&a,vector<int>&b,vector<vector<int>>&dp)
{
    if(i>=n|| j>=m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=0;
    int n1=call(i+1,j+1,n,m,a,b,dp);
    int n2=call(i,j+1,n,m,a,b,dp);
    int n3=call(i+1,j,n,m,a,b,dp);
    if(a[i]==b[j])
    {
        ans=max(ans,n1+1);
    }
    ans=max({ans,n1,n2,n3});
    return dp[i][j]=ans;
}
    int maxUncrossedLines(vector<int>&a,vector<int>&b)
    {
        int n=a.size(),m=b.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return call(0,0,n,m,a,b,dp);
        
    }
};