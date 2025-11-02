class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {
        int n=nums.size();
        
        int prev=2;
        int an=2;
        for(int i=2;i<n;i++)
        {
            if(nums[i]==(nums[i-1]+nums[i-2]))
            {
                prev++;
            }
            else
            prev=2;
            an=max(prev,an);
        }
        return an;
        
    }
};