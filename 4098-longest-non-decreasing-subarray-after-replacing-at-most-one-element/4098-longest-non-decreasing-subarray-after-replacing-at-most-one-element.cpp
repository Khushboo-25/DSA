class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n=nums.size();
        if(n<=1)
        return n;
        vector<int>av(n,1),pv(n,1);
        for(int i=1;i<n;i++)
        {
            if(nums[i]>=nums[i-1])
            av[i]=av[i-1]+1;
            
        }
        // for(int i=0;i<n;i++)
        // cout<<av[i]<<" ";
        // cout<<endl;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=nums[i+1])
            pv[i]=pv[i+1]+1;
        }
        // for(int i=0;i<n;i++)
        // cout<<pv[i]<<" ";
        // cout<<endl;
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(i>=1 && i<n-1 && nums[i-1]<=nums[i+1])
            {
                ans=max(ans,av[i-1]+pv[i+1]+1);
                // cout<<av[i-1]+pv[i+1]+1<<" ";
                
            }
            if(i-1>=0)
            ans=max(av[i-1]+1,ans);
            if(i+1<n)
            ans=max(pv[i+1]+1,ans);
        }
        return ans;
    }
};