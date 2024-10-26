class Solution {
public:
    int n1, n2, n3;

    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.size();
        n2 = s2.size();
        n3 = s3.size();

        // Check if the lengths don't match
        if (n1 + n2 != n3) return false;

        // Create a 2D DP table
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // Initialize the base case
        dp[0][0] = 1;

        // Fill the first row (when using only characters from s2)
        for (int j = 1; j <= n2; ++j) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        // Fill the first column (when using only characters from s1)
        for (int i = 1; i <= n1; ++i) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        // Fill the rest of the DP table
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        // The answer is in the bottom-right corner of the DP table
        return dp[n1][n2];
    }
};
