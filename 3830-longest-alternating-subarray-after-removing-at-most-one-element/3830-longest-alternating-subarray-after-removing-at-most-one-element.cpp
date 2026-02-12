class Solution {
public:
    int longestAlternating(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=1;
        vector<int>inc(n,1),dinc(n,1); //n-1<n
        vector<int>dec(n,1),ddec(n,1); //n-1>n
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            {
                inc[i]=max(inc[i],dec[i-1]+1);
            }
            else if(nums[i-1]>nums[i])
            {
                dec[i]=max(dec[i],inc[i-1]+1);
            }
        }
        for(int i=n-1;i>=1;i--)
        {
            if(nums[i-1]<nums[i])
            {
                dinc[i-1]=max(dinc[i-1],ddec[i]+1);
            }
            else if(nums[i-1]>nums[i])
            {
                ddec[i-1]=max(ddec[i-1],dinc[i]+1);
            }
        }
        for(auto it:inc)
        ans=max(ans,it);
        for(auto it:dec)
        ans=max(ans,it);
        for(int i=1;i<n-1;i++)
        {
            if(nums[i-1]>nums[i+1])
            ans=max(ans,inc[i-1]+dinc[i+1]);
            if(nums[i-1]<nums[i+1])
            ans=max(ans,dec[i-1]+ddec[i+1]);
        }
        return ans;

        
    }
};