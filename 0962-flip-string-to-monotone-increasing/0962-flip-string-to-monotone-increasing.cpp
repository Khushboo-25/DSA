class Solution {
public:
    int minFlipsMonoIncr(string s) 
    {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='0')
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=1+min(dp[i-1][0],dp[i-1][1]);
            }
            else
            {
                dp[i][0]=1+dp[i-1][0];
                dp[i][1]=min(dp[i-1][0],dp[i-1][1]);
            }
        }
        int ans= min(dp[n][1],dp[n][0]);
        return ans;
        
    }
};