class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int ans=1;
        vector<vector<int>>dp(n,vector<int>(2,1));
        // 0 first decresing
        // 1 first incresing
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>arr[i+1])
            dp[i][1]=max(dp[i+1][0]+1,dp[i][1]);
            else if(arr[i]<arr[i+1])
            dp[i][0]=max(dp[i+1][1]+1,dp[i][0]);
            ans=max({dp[i][0],dp[i][1],ans});
        }
        return ans;
    }
}; 