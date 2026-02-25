class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=nums[0];
        int p1=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                p1*=nums[i];
                ans=max(ans,p1);
            }
            else
            {
                p1=1;
                ans=max(ans,0);
            }          
        }
        p1=1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]!=0)
            {
                p1*=nums[i];
                ans=max(ans,p1);
            }
            else
            p1=1;
        }
        return ans;
        
    }
};