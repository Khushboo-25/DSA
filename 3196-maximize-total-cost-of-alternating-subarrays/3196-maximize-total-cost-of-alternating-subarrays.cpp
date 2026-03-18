class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) 
    {
        long long ans=0;
        long long s=0;
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            long long p1=1ll*nums[i]-s;
            if(p1>=0)
            {
                ans+=p1;
                s=0;
            }
            else
            {
                s=p1;
            }
        }
        ans+=s;
        return ans;
        
    }
};