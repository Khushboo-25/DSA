class Solution {
public:
    int numTeams(vector<int>& nums) 
    {
        int n=nums.size();
        // int ans=0;
        vector<int>fl(n,0),rl(n,0);
        vector<int>fg(n,0),rg(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    fl[i]++;
                }
                if(nums[j]>nums[i])
                {
                    fg[i]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]<nums[i])
                {
                    rl[i]++;
                }
                if(nums[j]>nums[i])
                {
                    rg[i]++;
                }
            }
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            int lf_lw=fl[i];
            int rf_lw=rl[i];
            int lf_g=fg[i];
            int rf_g=rg[i];
            ans+=lf_lw*rf_g;
            ans+=lf_g*rf_lw;

        }
        return ans;
        

        
    }
};