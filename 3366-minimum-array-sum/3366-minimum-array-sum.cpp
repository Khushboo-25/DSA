class Solution {
public:
int call(int i,int &n,vector<int>&nums,int &k,int op1,int op2,vector<vector<vector<int>>>&dp)
{
    if(i>=n)
    return 0;
    if(dp[i][op1][op2]!=-1)
    return dp[i][op1][op2];
    int ans=1e7;
    if(op1>0)
    ans=min(ans,(nums[i]+1)/2+call(i+1,n,nums,k,op1-1,op2,dp));

    if(op2>0 && nums[i]>=k)
    ans=min(ans,nums[i]-k+call(i+1,n,nums,k,op1,op2-1,dp));

    ans=min(ans,nums[i]+call(i+1,n,nums,k,op1,op2,dp));

    if(op1>0 && op2>0 && ((nums[i]+1)/2)>=k)
    ans=min(ans,(nums[i]+1)/2-k+call(i+1,n,nums,k,op1-1,op2-1,dp));

    if(op1>0 && op2>0 && nums[i]>=k)
    ans=min(ans,((nums[i]-k)+1)/2+call(i+1,n,nums,k,op1-1,op2-1,dp));
    return dp[i][op1][op2]=ans;
}
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));
        return call(0,n,nums,k,op1,op2,dp);
        
    }
};