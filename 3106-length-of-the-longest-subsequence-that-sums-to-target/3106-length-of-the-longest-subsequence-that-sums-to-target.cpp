class Solution {
public:
    int n;
    int solve(int target, int ind, vector<int> &nums, vector<vector<int>> &dp){
        // base
        if(target == 0){
            return 0;
        }
        if(ind == n){
            return -1e5;
        }
        if(dp[target][ind] != -1) return dp[target][ind];
        // take
        int take = -1e5;
        if(target >= nums[ind]){
            take = 1 + solve(target-nums[ind],ind+1,nums,dp);
        }
        //nottake
        int nottake = solve(target,ind+1,nums,dp);
        return dp[target][ind] = max(take,nottake);
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int k) {
        n= nums.size();
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        int ans = solve(k,0,nums,dp);
        return ans > 0 ? ans : -1;
    }
};