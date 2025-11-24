class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>av(n,1),pv(n,1);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            av[i]=av[i-1]+1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            pv[i]=pv[i+1]+1;
        }
        // for(auto it:av)
        // cout<<it<<" ";
        // cout<<endl;
        // for(auto it:pv)
        // cout<<it<<" ";
        int ans=1;
        for(int i=1;i<n;i++)
        {
            int ans1=min(av[i-1],pv[i]);
            ans=max(ans,ans1);
        }
        return ans;
        
    }
};