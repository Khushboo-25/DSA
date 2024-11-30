class Solution {
public:
int call(int i,int n,int op,vector<int> &nums,vector<vector<int>> &dp)
{
    if(i>=n)
    return 0;
    if(dp[i][op]!=-1)
    return dp[i][op];
    int ans=0;
    if(op==1)//take
    {
        
        ans=max(ans,nums[i]+call(i+1,n,0,nums,dp));
        ans=max(ans,call(i+1,n,1,nums,dp));
    }
    else
    {
        ans=max(ans,call(i+1,n,1,nums,dp));
    }
    return dp[i][op]=ans;
}
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<vector<int>>dp1(n+1,vector<int>(2,-1)),dp2(n+1,vector<int>(2,-1));
        return max(call(0,n-1,1,nums,dp1),call(1,n,1,nums,dp2));
        
    }
};