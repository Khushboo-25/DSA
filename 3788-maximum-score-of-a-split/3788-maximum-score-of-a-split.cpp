class Solution {
public:
    long long maximumScore(vector<int>& nums) 
    {
        int n=nums.size();
        vector<long long>ps(n,0);
        ps[0]+=nums[0];
        for(int i=1;i<n;i++)
        {
            ps[i]+=ps[i-1]+nums[i];
        }
        vector<int>mn(n,0);
        mn[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        mn[i]=min(nums[i],mn[i+1]);
        long long ans=LLONG_MIN;
        for(int i=0;i<n-1;i++)
        {
            ans=max(ps[i]-mn[i+1],ans);
        }
        return ans;
        
    }
};