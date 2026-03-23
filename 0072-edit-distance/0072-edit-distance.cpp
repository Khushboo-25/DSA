class Solution {
public:
int call(int i,int j,int &n,int&m,string &s,string &t,vector<vector<int>>&dp)
{
    if(j>=m)
    return (n-i); //rest delete
    if(i>=n)
    {
        return (m-j); // rest insert
    }
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=INT_MAX;
    if(s[i]==t[j])
    {
        ans=min(ans,call(i+1,j+1,n,m,s,t,dp)); // matched
    }
    ans=min(ans,1+call(i,j+1,n,m,s,t,dp));// inserted
    ans=min(ans,1+call(i+1,j,n,m,s,t,dp));//delete
    ans=min(ans,1+call(i+1,j+1,n,m,s,t,dp));// replace
    return dp[i][j]=ans;
}
    int minDistance(string s, string t) 
    {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return call(0,0,n,m,s,t,dp);
        
    }
};