class Solution {
public:
int call(int i,vector<int>&arr,int &d,int &n,vector<int>&dp)
{
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int ans=1;
    for(int j=i+1;j<=min(n-1,i+d);j++)
    {
        if(arr[i]>arr[j])
        {
            ans=max(ans,1+call(j,arr,d,n,dp));
        }
        else
        break;
    }
    for(int j=i-1;j>=max(0,i-d);j--)
    {
        if(arr[i]>arr[j])
        {
            ans=max(ans,1+call(j,arr,d,n,dp));
        }
        else
        break;
    }
    return dp[i]=ans;
}
    int maxJumps(vector<int>& arr, int d) 
    {
        int n=arr.size();
        // vector<int>dp(n+1,-1);
        int ans=0;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++)
        {
            int ans1=call(i,arr,d,n,dp);
            ans=max(ans,ans1);
            
        }
        
        return ans;
        
    }
};