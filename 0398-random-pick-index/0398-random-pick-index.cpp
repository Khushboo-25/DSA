class Solution {
public:
unordered_map<int,vector<int>>pp;

    Solution(vector<int>& nums) {
        int sz=nums.size();
        for(int i=0;i<sz;i++)
        {
            pp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int>av=pp[target];
        
        int rn=rand()%(av.size());
        return av[rn];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */