class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]<nums[j])
                ans=max(ans,nums[j]-nums[i]);
            }
        }
        return ans==INT_MIN?-1:ans;
    }
};