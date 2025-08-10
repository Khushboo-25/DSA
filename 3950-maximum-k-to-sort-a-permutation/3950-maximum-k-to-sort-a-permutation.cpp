class Solution {
public:

    int sortPermutation(vector<int>& nums) {
        
        int n=nums.size();
        int ans=n;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i)
            {
                ans=min(ans,nums[i] & nums[nums[i]]);
            }
        }
        return ans==n ?0:ans;
        
    }
};