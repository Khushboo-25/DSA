class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) 
    {
        for(auto &it: nums)
        {
            it=abs(it);
        }
        sort(nums.rbegin(),nums.rend());
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i<(n+1)/2) //5 0 1 2 3 4
            ans+=nums[i]*1ll*nums[i];
            else
            ans-=nums[i]*1ll*nums[i];
        }

        return ans;
        
    }
};