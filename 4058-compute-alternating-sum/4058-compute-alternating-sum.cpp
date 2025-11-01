class Solution {
public:
    int alternatingSum(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i%2)
            ans-=nums[i];
            else
            ans+=nums[i];
        }
        return ans;
        
    }
};