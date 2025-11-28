class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> *g;
    
    int dfs(int r, int c) {
        if (c == n - 1) return 0; // last col → no more moves
        
        if (dp[r][c] != -1) return dp[r][c];
        
        int best = 0;
        int curr = (*g)[r][c];

        // 3 directions: up-right, right, down-right
        int dr[3] = {-1, 0, 1};

        for (int k = 0; k < 3; k++) {
            int nr = r + dr[k];
            int nc = c + 1;
            if (nr >= 0 && nr < m && (*g)[nr][nc] > curr) {
                best = max(best, 1 + dfs(nr, nc));
            }
        }
        return dp[r][c] = best;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        g = &grid;

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        // start from any cell in first column
        for (int r = 0; r < m; r++) {
            ans = max(ans, dfs(r, 0));
        }
        return ans;
    }
};
