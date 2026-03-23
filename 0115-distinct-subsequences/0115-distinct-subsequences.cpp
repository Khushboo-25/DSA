class Solution {
public:
int call(int i,int j,int &n,int &m,string &s,string &t,vector<vector<int>>&dp)
{
    if(i>=n)
    {
        if(j>=m)
        return 1;
        return 0;
    }
    if(j>=m)
    return 1;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=0;
    if(s[i]==t[j])
    {
        ans+=call(i+1,j+1,n,m,s,t,dp);
    }
    ans+=call(i+1,j,n,m,s,t,dp);
    return dp[i][j]=ans;
}
    int numDistinct(string s, string t) 
    {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return call(0,0,n,m,s,t,dp);
        
    }
};