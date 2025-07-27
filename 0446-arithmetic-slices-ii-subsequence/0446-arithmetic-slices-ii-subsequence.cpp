class Solution {
public:
    int n;
    vector<int> nums;
    vector<unordered_map<long long, int>> dp;

    // This function returns how many subsequences of length ≥ 2 ending at i with 'diff'
    int call(int i, long long diff) {
        if (dp[i].count(diff))
            return dp[i][diff];

        int total = 0;
        for (int j = 0; j < i; j++) {
            if (1LL * nums[i] - nums[j] == diff) {
                int prev = call(j, diff);
                total += prev + 1;  // +1 for the pair (nums[j], nums[i])
            }
        }
        return dp[i][diff] = total;
    }

    int numberOfArithmeticSlices(vector<int>& _nums) {
        nums = _nums;
        n = nums.size();
        dp.resize(n);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = 1LL * nums[i] - nums[j];
                int prev = call(j, diff);
                ans += prev;  // Only add subsequences of length ≥ 2 ending at j — extended to length ≥ 3 at i
            }
        }
        return ans;
    }
};
