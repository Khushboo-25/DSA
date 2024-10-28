class Solution {
public:
int cal(string &s)
{
    int ans=0;
    for(auto it:s)
    {
        ans+=it;
    }
    return ans;
}
int call(int i,int j,int &n1,int &n2,string &s1,string &s2,vector<vector<int>>&dp)
{
    if(i>=n1 || j>=n2)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    return dp[i][j];
    int f1=0;
    if(s1[i]==s2[j])
    {
        f1=max(f1,s1[i]+call(i+1,j+1,n1,n2,s1,s2,dp));
    }
    f1=max(f1,call(i+1,j,n1,n2,s1,s2,dp));
    f1=max(f1,call(i,j+1,n1,n2,s1,s2,dp));
    return dp[i][j]=f1;
}
    int minimumDeleteSum(string s1, string s2) 
    {
        
        // int ans=0;
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        int ans=call(0,0,n1,n2,s1,s2,dp);
        int ans1=cal(s1)+cal(s2)-2*ans;
        return ans1;


        
    }
};