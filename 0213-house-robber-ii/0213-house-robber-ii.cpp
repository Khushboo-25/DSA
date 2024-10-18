class Solution {
public:

int call(int in,int t1,vector<int> nums,int n,vector<vector<int>> &dp)
{
    if(in>=n)
    return 0;
    if(dp[in][t1]!=-1)
    return dp[in][t1];
    int sum=0;
    if(t1==1) //tak
    {
        sum=max(sum,nums[in]+call(in+1,0,nums,n,dp));
        sum=max(sum,call(in+1,1,nums,n,dp));
    }
    else
    {
        sum=max(sum,call(in+1,1,nums,n,dp));
        // sum=max(sum,call(in+1,1,nums,n,dp));
    }
    
    return dp[in][t1]=sum;
}
    
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(nums.size()==1)
        return nums[0];
        vector<vector<int>> dp1(n+1,vector<int>(2,-1)),dp2(n+1,vector<int>(2,-1));
        return max(call(0,1,nums,n-1,dp1),call(1,1,nums,n,dp2));
        
    }
};