class Solution {
public:
int call(int prev,int in,int diff,vector<int> &nums,int &n,vector<vector<vector<int>>>&dp)
{
    
    if(in>=n)
    {
        return 0;
    }
    if(dp[prev][in][diff]!=-1)
    return dp[prev][in][diff];
    int len=0;
    if(diff==0) /// neg
    {
        if(nums[in]<prev-1)
        {
            len=max(len,1+call(nums[in]+1,in+1,1,nums,n,dp));
        }
        len=max(len,call(prev,in+1,0,nums,n,dp));
    }
    else
    {
        if(nums[in]>prev-1)
        {
            len=max(len,1+call(nums[in]+1,in+1,0,nums,n,dp));
        }
        len=max(len,call(prev,in+1,1,nums,n,dp));
    }
    return dp[prev][in][diff]=len;
}
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<int>>>dp1(1003,vector<vector<int>>(n+1,vector<int>(2,-1)));
        vector<vector<vector<int>>>dp2(1003,vector<vector<int>>(n+1,vector<int>(2,-1)));
        
        int ans=0;
        ans=max(ans,call(1002,0,0,nums,n,dp1));
        ans=max(ans,call(0,0,1,nums,n,dp2));
        return ans;
    }
};