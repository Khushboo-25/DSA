class Solution {
public:
int call(int i,int &n,vector<int> &nums,int tt,vector<vector<int>>&dp)
{
    if(tt<=0)
    {
        return 0;
    }
    if(i>=n )
    return INT_MIN;
    if(dp[i][tt]!=INT_MIN)
    return dp[i][tt];
    int len=INT_MIN;
    if(nums[i]<=tt)
    {
        int len1=call(i+1,n,nums,tt-nums[i],dp);
        
        len=max(len1+1,len);

        // len=max(len,len1+1);
    }
    int len2=call(i+1,n,nums,tt,dp);
    // if(len2!=-1)
    len=max(len,len2);
    return dp[i][tt]=len;

}
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        // int ans=-1;
        vector<vector<int>>dp(n+1,vector<int> (target+1,INT_MIN));

        int ans=call(0,n,nums,target,dp);
        if(ans>0)
        return ans;
        return -1;
        
        // return ans;
        
    }
};