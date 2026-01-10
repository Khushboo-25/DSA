class Solution {
public:
    int minimumOperations(vector<int>& nums)
    {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(4,INT_MIN));
        dp[0][1]=0;
        dp[0][2]=0;
        dp[0][3]=0;
        for(int i=1;i<=n;i++)
        {
            if(nums[i-1]==1)
            {
                dp[i][1]=max(dp[i-1][1]+1,dp[i][1]);
                dp[i][2]=max(dp[i-1][2],dp[i][2]);
                dp[i][3]=max(dp[i-1][3],dp[i][3]);
            }
            else if(nums[i-1]==2)
            {
                dp[i][1]=max(dp[i-1][1],dp[i][1]);
                dp[i][2]=max({dp[i-1][2]+1,dp[i-1][1]+1,dp[i][2]});
                dp[i][3]=max({dp[i][3],dp[i-1][3]});
            }
            else // 3
            {
                dp[i][1]=max(dp[i-1][1],dp[i][1]);
                dp[i][2]=max({dp[i-1][2],dp[i][2]});
                dp[i][3]=max({dp[i-1][3]+1,dp[i-1][2]+1,dp[i-1][1]+1,dp[i][3]});
            }
        }
        return n-max({dp[n][1],dp[n][2],dp[n][3]});
        
    }
};