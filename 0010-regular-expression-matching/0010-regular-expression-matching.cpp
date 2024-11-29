class Solution {
public:
bool helper(int i,int j,string &s,string &p,vector<vector<int>>&dp)
{
    if(j>=s.size())
    return 1;
    if(dp[i][j]!=-1)
    return dp[i][j];

    if(p[j]!='*')
    {
        if(s[i]==p[j] || p[j]=='.')
        return dp[i][j]=helper(i+1,j+1,s,p,dp);
        return 0;
    }
    if(p[j]=='*')
    {
        return helper(i,j+1,s,p,dp)||helper(i+1,j+1,s,p,dp);
    }
    return 0;
    
    
}
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return helper(0,0,s,p,dp);
    }
};