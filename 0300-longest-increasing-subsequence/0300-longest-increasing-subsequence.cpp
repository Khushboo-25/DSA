class Solution {
public:
    int call(int in, int prev, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (in >= n) 
            return 0;

        if (dp[in][prev + 1] != -1) 
            return dp[in][prev + 1];

        // Option 1: Include current element if it forms an increasing subsequence
        int take = 0;
        if (prev == -1 || nums[in] > nums[prev]) {
            take = 1 + call(in + 1, in, nums, n, dp);
        }

        // Option 2: Skip the current element
        int skip = call(in + 1, prev, nums, n, dp);

        // Store the result and return the maximum of both options
        return dp[in][prev + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // DP table: dp[in][prev + 1] -> initialized to -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return call(0, -1, nums, n, dp);
    }
};
