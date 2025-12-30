class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();

        // Step 1: apply gravity
        for (int i = 0; i < n; i++) {
            int empty = m - 1;
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    empty = j - 1;
                } 
                else if (box[i][j] == '#') {
                    swap(box[i][j], box[i][empty]);
                    empty--;
                }
            }
        }

        // Step 2: rotate clockwise
        vector<vector<char>> ans(m, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][n - i - 1] = box[i][j];
            }
        }

        return ans;
    }
};
