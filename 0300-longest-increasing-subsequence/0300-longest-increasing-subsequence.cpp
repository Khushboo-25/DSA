class Solution {
public:
int call(int in,int prev,vector<int> &nums,int &n,vector<vector<int>>&dp)
{
    if(in>=n)
    return 0;
    if(dp[in][prev+1]!=-1)
    return dp[in][prev+1];
    
    if(prev==-1 || nums[in]>nums[prev])
    {
        return dp[in][prev+1]=max(1+call(in+1,in,nums,n,dp),call(in+1,prev,nums,n,dp));
    }
    else
    return dp[in][prev+1]=call(in+1,prev,nums,n,dp);
}
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return call(0,-1,nums,n,dp);
        
    }
};