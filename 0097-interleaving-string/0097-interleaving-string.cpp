class Solution {
public:
int n1,n2,n3;
bool call(int i,int j,int l,string s1,string s2,string s3,vector<vector<vector<int>>>&dp)
{
    if(j==n1)
    return s3.substr(i)==s2.substr(l);
    else if(l==n2)
    return s3.substr(i)==s1.substr(j);
    if(dp[i][j][l]!=-1)
    return dp[i][j][l];
    if(s1[j]!=s2[l])
    {
        if(s1[j]==s3[i])
        return dp[i][j][l]=call(i+1,j+1,l,s1,s2,s3,dp);
        else if(s2[l]==s3[i])
        return dp[i][j][l]=call(i+1,j,l+1,s1,s2,s3,dp);
        else 
        return dp[i][j][l]=0;
    }
    else
    {
        if(s3[i]!=s1[j]) 
        return dp[i][j][l]=0;
        return dp[i][j][l]=call(i+1,j+1,l,s1,s2,s3,dp)|call(i+1,j,l+1,s1,s2,s3,dp);

    }
}
    bool isInterleave(string s1, string s2, string s3) 
    {
        
        n1=s1.size(),n2=s2.size(),n3=s3.size();
        vector<vector<vector<int>>>dp(n3+1,vector<vector<int>>(n1+1,vector<int>(n2+1,-1)));
        return call(0,0,0,s1,s2,s3,dp);
    }
};