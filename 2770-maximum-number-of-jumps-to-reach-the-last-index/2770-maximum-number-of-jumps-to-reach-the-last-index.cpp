class Solution {
public:

int maximumJumps(vector<int>& nums,int tt)
{
    int n=nums.size();
    vector<int>dp(n,-1e4);
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(abs(nums[i]-nums[j])<=tt)
            dp[j]=max(dp[i]+1,dp[j]);
        }
    }
    if(dp[n-1]<=0)
    return -1;
    return dp[n-1];
}
};