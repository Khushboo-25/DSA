class Solution {
public:

long long calldsc(int s,int aff,vector<int> &a,vector<long long>&dp)
{
    if(s<0)
    return 0;
    if(a[s]<a[aff])
    {
        return dp[aff]=a[s]+calldsc(s-1,s,a,dp);
    }
    else
    {
        return dp[aff]=a[aff]+calldsc(s-1,aff,a,dp);
    }
    
}
long long callinc(int e,int &n,int prev,vector<int>&a,vector<long long> &dp)
{
    if(e>=n)
    return 0;
    if(a[e]<a[prev])
    return dp[prev]=a[e]+callinc(e+1,n,e,a,dp);
    return dp[prev]=a[prev]+callinc(e+1,n,prev,a,dp);
}
    long long maximumSumOfHeights(vector<int>& a) {
         long long ans=0;
        int n=a.size();
        vector<long long>dp1(n,-1);
        vector<long long>dp2(n,-1);
        for(int i=0;i<n;i++)
        {
            long long sumleft=calldsc(i-1,i,a,dp1);
            long long sumright=callinc(i+1,n,i,a,dp2);
            ans=max(ans,sumleft+sumright+a[i]);

        }
        return ans;
    }
};