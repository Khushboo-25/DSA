class Solution {
public:
int call(int i,int j,int &n,int &m,string &s,string &t,vector<vector<int>>&dp)
{
    if(j<0)
    {
        return i<0;
    }
    if(i<0)
    {
        for(int k=j;k>=0;k--)
        {
            if(t[k]!='*')
            return 0;
        }
        return 1;
    }
    if(dp[i][j]!=-1)
    return dp[i][j];
    if((s[i]==t[j] ||t[j]=='?') && call(i-1,j-1,n,m,s,t,dp))
    return dp[i][j]=1;
    if(t[j]=='*' && (call(i-1,j,n,m,s,t,dp) ||call(i,j-1,n,m,s,t,dp) || call(i-1,j-1,n,m,s,t,dp)))
    {
        return dp[i][j]=1;
    }
    return dp[i][j]=0;
    

}
    bool isMatch(string s, string t) 
    {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return call(n-1,m-1,n,m,s,t,dp);
        
    }
};