class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) 
    {
        int n=nums.size();
        vector<long long>ans(n,0);
        ans[0]=nums[0]*1ll*2;
        int mx=nums[0];
        for(int i=1;i<n;i++)
        {
            mx=max(mx,nums[i]);
            ans[i]=ans[i-1]+mx+nums[i];
        }
        return ans;
        
    }
};