class Solution {
public:
bool call(int i,int j,int &n,int &m,string &s,string &p,vector<vector<int>> &dp)
{ 
    if(j>=m && i>=n)
    return 1;

    else if(j>=m)
    {   
        if(s[i]=='*')
        return  call(i+1,j,n,m,s,p,dp);
        // else
        return 0;
    } 
    else if(i>=n)
    {
        if(p[j]=='*')
        return call(i,j+1,n,m,s,p,dp);
        return 0;
    }
    else if(dp[i][j]!=-1)
    return dp[i][j];
    else if(s[i]=='*' || p[j]=='*')
    {
        return dp[i][j]=call(i+1,j+1,n,m,s,p,dp)||call(i+1,j,n,m,s,p,dp)|| 
        call(i,j+1,n,m,s,p,dp);
    }
    
    else if(s[i]=='?' || p[j]=='?')
    {
        return dp[i][j]=call(i+1,j+1,n,m,s,p,dp);
    }
    else if(s[i]!=p[j])
    return dp[i][j]=0;
    else 
    return dp[i][j]=call(i+1,j+1,n,m,s,p,dp);
}
    bool isMatch(string s, string p) 
    {
        int n=s.size(),m=p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return call(0,0,n,m,s,p,dp);

        
    }
};