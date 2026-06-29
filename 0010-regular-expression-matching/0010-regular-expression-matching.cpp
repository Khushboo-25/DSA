class Solution {
public:
bool call(int i,int j,int &n,int &m,string &s,string &p,vector<vector<int>>&dp)
{
    if(j>=m)
    return i>=n;
    if(dp[i][j]!=-1)
    return dp[i][j];
    bool nextst=0;
    if(j+1<m && p[j+1]=='*')
    nextst=1;
    if(nextst)
    {
        bool a=0,b=0;
        if(i<n && (s[i]==p[j] || p[j]=='.'))
        a=call(i+1,j,n,m,s,p,dp);
        b=call(i,j+2,n,m,s,p,dp);
        return dp[i][j]=a|b;
    }
    else
    {
        if(i<n && (s[i]==p[j]|| p[j]=='.'))
        return dp[i][j]=call(i+1,j+1,n,m,s,p,dp);
    }

    return dp[i][j]= 0;
    
}
    bool isMatch(string s, string p) 
    {
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return call(0,0,n,m,s,p,dp);
    }
};