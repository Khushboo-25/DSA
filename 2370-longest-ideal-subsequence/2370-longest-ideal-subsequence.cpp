class Solution {
public:
int call(int ls,int i,int &n,string &s,int &k,vector<vector<int>>&dp)
{
    if(i>=n)
    return 0;
    if(dp[ls][i]!=-1)
    return dp[ls][i];
    int ans=0;
    int c1=s[i]-'a';
    if(abs(c1-ls)<=k)
    {
        ans=max(ans,1+call(c1,i+1,n,s,k,dp));
    }
    ans=max(ans,call(ls,i+1,n,s,k,dp));
    return dp[ls][i]=ans;
}
    int longestIdealString(string s, int k) 
    {
        int ans=1;
        int n=s.size();
        vector<vector<int>>dp(26,vector<int>(n+1,-1));
        for(int i=0;i<n;i++)
        {
            int ls=s[i]-'a';
            ans=max(ans,1+call(ls,i+1,n,s,k,dp));
        }
        return ans;
        
    }
};