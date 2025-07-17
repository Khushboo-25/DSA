class Solution {
public:

    
    int maximumLength(vector<int>& nums) {
 
        vector<vector<int>>dp(2,vector<int>(2));
        int ans = 0; 
        for (int n : nums) {
            int x = n % 2; 
            //prev x, next y

            for (int y = 0; y < 2; y++) {
                
                dp[x][y] = dp[y][x] + 1; 
                ans = max(ans, dp[x][y]);
            }
        }
        return ans;
        
    }
};