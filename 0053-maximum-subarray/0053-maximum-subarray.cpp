class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int ans=nums[0];
        int s=0;
        for(auto it:nums)
        {
            if(s+it<=it)
            {
                s=it;
            }
            else
            s+=it;
            ans=max(ans,s);
        }
        return ans;
        
    }
};