class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int>pp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pp.find(nums[i])!=pp.end() && (i-pp[nums[i]])<=k)
            {
                return 1;
            }
            pp[nums[i]]=i;
        }
        return 0;
        
    }
};