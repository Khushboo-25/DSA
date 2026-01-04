class Solution {
public:
    unordered_map<int,int> dp;

    int minDays(int n) {
        if (n <= 1) return n;
        if (dp.count(n)) return dp[n];

        int ans = n;  // worst case: eat 1 per day

        ans = min(ans, 1 + (n % 2) + minDays(n / 2));
        ans = min(ans, 1 + (n % 3) + minDays(n / 3));

        return dp[n] = ans;
    }
};
