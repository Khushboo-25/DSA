class Solution {
public:
    int call(int prev, int in, int diff, vector<int>& nums, int n, vector<vector<vector<int>>>& dp) {
        if (in >= n) return 0;

        if (dp[prev + 1][in][diff] != -1)  // +1 to handle -1 index
            return dp[prev + 1][in][diff];

        int len = 0;

        // If we're in the "negative slope" phase (diff == 0)
        if (diff == 0) {
            if (prev == -1 || nums[in] < nums[prev]) {
                len = max(len, 1 + call(in, in + 1, 1, nums, n, dp));  // Switch to positive slope
            }
            len = max(len, call(prev, in + 1, 0, nums, n, dp));  // Stay in negative slope
        }
        // If we're in the "positive slope" phase (diff == 1)
        else {
            if (prev == -1 || nums[in] > nums[prev]) {
                len = max(len, 1 + call(in, in + 1, 0, nums, n, dp));  // Switch to negative slope
            }
            len = max(len, call(prev, in + 1, 1, nums, n, dp));  // Stay in positive slope
        }

        return dp[prev + 1][in][diff] = len;
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        // DP table: (n + 1) * (n + 1) * 2
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));

        // Start with no previous element, trying both increasing and decreasing sequences
        return max(call(-1, 0, 0, nums, n, dp), call(-1, 0, 1, nums, n, dp));
    }
};
