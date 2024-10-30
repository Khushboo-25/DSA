class Solution {
public:
int callinc(vector<int> &nums,int prev,int e,int &n,vector<int> &dp)
{
    if(e>=n || prev>=n-1)
    return 0;
    if(dp[prev]!=-1)
    return dp[prev];
    int len=0;
    if(nums[e]<nums[prev])
    {
        return dp[prev]=1+callinc(nums,e,e+1,n,dp);
    }
    return dp[prev]=0;
}
int calldec(vector<int> &nums,int s,int aff,int &n,vector<int> &dp)
{
    if(s<0 ||aff<=0)
    return 0;
    if(dp[aff]!=-1)
    return dp[aff];
    int len=0;
    if(nums[s]<nums[aff])
    {
        return dp[aff]=1+calldec(nums,s-1,s,n,dp);
    }
    return dp[aff]=0;
}
    int longestMountain(vector<int>& nums) 
    {
         int n=nums.size();
        int ans=0;
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        for(int i=1;i<n-1;i++)
        {
            
            int leftlen=calldec(nums,i-1,i,n,dp1);
            int rightlen=callinc(nums,i,i+1,n,dp2);

            if(leftlen>0 && rightlen>0)
            ans=max(ans,leftlen+1+rightlen);

        }
        return ans;
    }
};
