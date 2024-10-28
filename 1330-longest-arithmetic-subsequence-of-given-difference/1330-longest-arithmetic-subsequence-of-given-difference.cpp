class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> dp; // Stores the longest subsequence ending with each value
        int maxLength = 0;

        for (int num : arr) {
            // If num - diff exists, extend that subsequence, otherwise start a new one
            dp[num] = dp[num - diff] + 1;
            maxLength = max(maxLength, dp[num]); // Update max length
        }

        return maxLength;
    }
};
