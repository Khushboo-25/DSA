class Solution {
public:
    int longestSquareStreak(vector<int>& nums)
    {
        vector<int>dp(1e5+1,0);
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int c=nums[i];
            int sr=sqrt(c);
            if((sr*sr)==c)
            {
                dp[c]=max(dp[c],dp[sr]+1);
            }
            else
            dp[c]=1;
        }
        int ans=*max_element(dp.begin(),dp.end());
        if(ans<=1)
        return -1;
        return ans;

        
    }
};