class Solution {
public:
int dp[502][501][26];
int call(int pr,int i,int &n,vector<int>&nums,int lf)
{
    if(i>=n)
    return 0;
    int ans=0;
    if(dp[pr+1][i][lf]!=-1)
    return dp[pr+1][i][lf];
    if(pr==-1)
    {
        ans=max(ans,call(pr,i+1,n,nums,lf));
        ans=max(ans,1+call(i,i+1,n,nums,lf));
    }
    else
    {
        if(nums[i]!=nums[pr])
        {
            if(lf>0)
            ans=max(ans,1+call(i,i+1,n,nums,lf-1));
            ans=max(ans,call(pr,i+1,n,nums,lf));
        }
        else
        {
            ans=max(ans,1+call(i,i+1,n,nums,lf));
            ans=max(ans,call(pr,i+1,n,nums,lf));
        }
    }
    return dp[pr+1][i][lf]=ans;
}
    int maximumLength(vector<int>& nums, int k) 
    {
        int n=nums.size();
        memset(dp,-1,sizeof(int)*502*501*26);
        return call(-1,0,n,nums,k);
        
    }
};