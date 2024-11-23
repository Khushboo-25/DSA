class Solution {
public:
    bool isPal(string& str, int s, int e, vector<vector<int>>& isPaldp) {
        if (s >= e) return true; // Correct base case for palindrome check

        if (isPaldp[s][e] != -1) return isPaldp[s][e];

        if (str[s] == str[e]) {
            return isPaldp[s][e] = isPal(str, s + 1, e - 1, isPaldp);
        } else {
            return isPaldp[s][e] = false;
        }
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, INT_MAX); // Initialize with INT_MAX for min comparison
        vector<vector<int>> isPaldp(n, vector<int>(n, -1));

        // Precompute the palindrome status
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                isPal(s, i, j, isPaldp);
            }
        }

        dp[n] = 0; // No cuts needed for an empty substring

        for (int i = n - 1; i >= 0; --i) {
            int cuts = INT_MAX;
            for (int j = i; j < n; ++j) {
                if (isPaldp[i][j]) {
                    cuts = min(cuts, 1 + dp[j + 1]);
                }
            }
            dp[i] = cuts;
        }

        return dp[0] - 1;
    }
};