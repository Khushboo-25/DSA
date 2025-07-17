class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>>dp(k+1,vector<int>(k+1));
        int ans = 0; 
        for (int n : nums) {
            int x = n % k; 
            //prev x, next y

            for (int y = 0; y < k; y++) {
                
                dp[x][y] = dp[y][x] + 1; 
                ans = max(ans, dp[x][y]);
            }
        }
        return ans;
    }
};