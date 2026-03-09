class Solution {
public:
bool call(int tm,int &sm,vector<int>&nums,int i,int &n,vector<vector<int>>&dp)
{
    if(i>=n)
    {
        if(tm!=sm)
        return 0;
        return 1;
    }
    if(dp[i][tm]!=-1)
    return dp[i][tm];
    if(tm+nums[i]<=sm && call(tm+nums[i],sm,nums,i+1,n,dp))
    return dp[i][tm]=1;
    if(call(tm,sm,nums,i+1,n,dp))
    return dp[i][tm]=1;
    return dp[i][tm]=0;
}
    bool canPartition(vector<int>& nums) 
    {
        
        int n=nums.size();
        int sm=0;
        for(auto it:nums)
        sm+=it;

        if(sm%2==1 || n==1)
        return 0;
        vector<vector<int>>dp(n+1,vector<int>(sm/2+1,-1));
        sm/=2;
        if(call(0,sm,nums,0,n,dp))
        return 1;
        return 0;
        
    }
};