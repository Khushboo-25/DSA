class Solution {
public:
    int longestArithSeqLength(vector<int>& nums)
    {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(1002,1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int df=nums[j]-nums[i];
                dp[j][df+500]=max(dp[j][df+500],dp[i][df+500]+1);
            }
        }
        int ans=1;
        for(int i=0;i<n;i++)
        {
            for(int j=-500;j<=500;j++)
            ans=max(dp[i][j+500],ans);
        }
        return ans;
        
        
    }
};