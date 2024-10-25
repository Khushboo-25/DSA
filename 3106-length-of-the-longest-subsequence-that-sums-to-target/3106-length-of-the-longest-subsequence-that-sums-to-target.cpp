class Solution {
public:
int call(int i,int &n,vector<int> &nums,int tt,vector<vector<int>>&dp)
{
    if(tt<=0)
    {
        return 0;
    }
    if(i>=n)
    return -1e5;
    if(dp[tt][i]!=-1)
    return dp[tt][i];
    int len=-1e5;
    if(nums[i]<=tt)
    {
        int len1=call(i+1,n,nums,tt-nums[i],dp);
        len=max(len,len1+1);
    }

    int len2=call(i+1,n,nums,tt,dp);
    len=max(len,len2);

    return dp[tt][i]=len;

}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        // int ans=-1;
        vector<vector<int>>dp(target+1,vector<int>(n+1,-1));
        int ans=call(0,n,nums,target,dp);
        if(ans>0)
        return ans;
        return -1;
        
        // return ans;
        
    }
};