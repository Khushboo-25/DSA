class Solution {
public:
int call(int i,int j,int &n,int &m,string &s,string &p,vector<vector<int>>&dp)
{
    if(i>=n && j>=m)
    return 0;
    if(i>=n)
    {
        return m-j;
    }
    else if(j>=m)
    {
        return n-i;
    }
    else if(dp[i][j]!=-1)
    return dp[i][j];
    else if(s[i]!=p[j])
    {
        int n1=1+call(i+1,j,n,m,s,p,dp);
        int n2=1+call(i,j+1,n,m,s,p,dp);
        int n3=1+call(i+1,j+1,n,m,s,p,dp);
        return dp[i][j]=min(n1,min(n2,n3));
    }
    else
    {
        return dp[i][j]=call(i+1,j+1,n,m,s,p,dp);
    }
    

}
    int minDistance(string s, string p) 
    {
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return call(0,0,n,m,s,p,dp);
        
    }
};