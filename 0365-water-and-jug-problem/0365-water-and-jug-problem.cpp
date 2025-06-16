class Solution {
public:
    bool call(int i, int j, int x, int y, int tt, vector<vector<int>> &dp) {
        if (i + j == tt) return true;
        if (dp[i][j] != -1) return dp[i][j];

        dp[i][j] = 0; // mark as visited to prevent infinite recursion

        // Fill jug x
        if (call(x, j, x, y, tt, dp)) return dp[i][j] = 1;
        // Fill jug y
        if (call(i, y, x, y, tt, dp)) return dp[i][j] = 1;
        // Empty jug x
        if (call(0, j, x, y, tt, dp)) return dp[i][j] = 1;
        // Empty jug y
        if (call(i, 0, x, y, tt, dp)) return dp[i][j] = 1;
        // Pour x -> y
        int pourXY = min(i, y - j);
        if (call(i - pourXY, j + pourXY, x, y, tt, dp)) return dp[i][j] = 1;
        // Pour y -> x
        int pourYX = min(j, x - i);
        if (call(i + pourYX, j - pourYX, x, y, tt, dp)) return dp[i][j] = 1;

        return dp[i][j] = 0;
    }

    bool canMeasureWater(int x, int y, int tt) {
        if (tt > x + y) return false; // can't measure more than total capacity
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, -1));
        return call(0, 0, x, y, tt, dp);
    }
};
