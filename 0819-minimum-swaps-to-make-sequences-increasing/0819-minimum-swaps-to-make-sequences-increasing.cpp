class Solution {
public:
    int minSwap(vector<int>& a, vector<int>& b) 
    {
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(2,INT_MAX));
        dp[n-1][0]=0;
        dp[n-1][1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(a[i]<a[i+1] && b[i]<b[i+1])
            {
                dp[i][0]=min(dp[i][0],dp[i+1][0]);
                dp[i][1]=min(dp[i][1],1+dp[i+1][1]);
            }
            if(a[i]<b[i+1] && b[i]<a[i+1])
            {
                dp[i][0]=min(dp[i][0],dp[i+1][1]);
                dp[i][1]=min(dp[i][1],1+dp[i+1][0]);
            }
        }
        return min(min(n-dp[0][0],dp[0][0]),min(n-dp[0][1],dp[0][1]));
    }
};