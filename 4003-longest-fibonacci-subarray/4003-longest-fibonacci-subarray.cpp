class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n=nums.size();
        
        vector<int> ans(n,2);
        for(int i=2;i<n;i++)
        {
            if(nums[i]==(nums[i-1]+nums[i-2]))
            {
                ans[i]=ans[i-1]+1;
            }
            cout<<ans[i]<<" ";
        }
        return*max_element(ans.begin(),ans.end());
        
    }
};