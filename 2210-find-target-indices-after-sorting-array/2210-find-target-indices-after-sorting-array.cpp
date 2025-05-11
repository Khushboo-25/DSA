class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int tt) {
        sort(nums.begin(),nums.end());
        int i1=upper_bound(nums.begin(),nums.end(),tt-1)-nums.begin();
        int i2=upper_bound(nums.begin(),nums.end(),tt)-nums.begin();
        vector<int> ans;
        for(int i=i1;i<=i2-1;i++)
        {
            ans.push_back(i);
        }
        return ans;
        
    }
};