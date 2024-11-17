class Solution {
public:
    int find(vector<int> &dp, vector<int>& nums, int target){
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        if(target==0) return 1;
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans+= find(dp,nums,target-nums[i]);
        }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target+1,-1);
        return find(dp,nums,target);
    }
};