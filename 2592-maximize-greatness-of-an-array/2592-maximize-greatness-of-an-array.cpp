class Solution {
public:
    int maximizeGreatness(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int ans= 0;
        for (int it : nums)
            if (it > nums[ans])
                ans++;
        return ans;
        
    }
};