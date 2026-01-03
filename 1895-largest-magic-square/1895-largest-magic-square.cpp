
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));

        // Build prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
            }
        }

        int ans = 1;

        for (int k = 2; k <= min(m, n); k++) {
            for (int r = 0; r + k <= m; r++) {
                for (int c = 0; c + k <= n; c++) {

                    int target = row[r][c + k] - row[r][c];
                    bool ok = true;

                    // Check rows
                    for (int i = 0; i < k && ok; i++) {
                        if (row[r + i][c + k] - row[r + i][c] != target)
                            ok = false;
                    }

                    // Check columns
                    for (int j = 0; j < k && ok; j++) {
                        if (col[r + k][c + j] - col[r][c + j] != target)
                            ok = false;
                    }

                    // Check diagonals
                    int d1 = 0, d2 = 0;
                    for (int i = 0; i < k; i++) {
                        d1 += grid[r + i][c + i];
                        d2 += grid[r + i][c + k - 1 - i];
                    }

                    if (ok && d1 == target && d2 == target)
                        ans = max(ans, k);
                }
            }
        }
        return ans;
    }
};
