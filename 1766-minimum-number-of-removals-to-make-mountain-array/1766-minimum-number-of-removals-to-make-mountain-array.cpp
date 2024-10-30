class Solution {
public:
int callinc(vector<int> &nums,int s,int prev,int &n,vector<vector<int>> &dp)
{
    if(s>=n || prev>=n-1)
    return 0;
    if(dp[s][prev]!=-1)
    return dp[s][prev];
    int len=0;
    if(nums[s]<nums[prev])
    {
        len=max(len,1+callinc(nums,s+1,s,n,dp));
    }
    
    len=max(len,callinc(nums,s+1,prev,n,dp));
    
    return dp[s][prev]=len;
}
int calldec(vector<int> &nums,int e,int aff,int &n,vector<vector<int>> &dp)
{
    if(e<0 || aff<=0)
    return 0;
    if(dp[e][aff]!=-1)
    return dp[e][aff];
    int len=0;
    if(nums[e]<nums[aff])
    {
        len=max(len,1+calldec(nums,e-1,e,n,dp));
    }
    len=max(len,calldec(nums,e-1,aff,n,dp));
    
    return dp[e][aff]=len;
}
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n=nums.size();
        int del=INT_MAX;
        vector<vector<int>> dp1(n,vector<int>(n,-1));
        vector<vector<int>> dp2(n,vector<int>(n,-1));
        for(int i=1;i<n-1;i++)
        {
            
            int leftlen=calldec(nums,i-1,i,n,dp1);
            int rightlen=callinc(nums,i+1,i,n,dp2);

            if(leftlen>0 && rightlen>0)
            del=min(n-leftlen-1-rightlen,del);

        }
        return del;
        
    }
};