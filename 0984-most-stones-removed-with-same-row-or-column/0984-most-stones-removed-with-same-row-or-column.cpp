class Solution {
public:
    void dfs(int idx, int n, vector<bool>& visited, vector<vector<int>>& stones) {
        visited[idx] = true;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // same row
                if (stones[i][0] == stones[idx][0]) {
                    dfs(i, n, visited, stones);
                }
                // same col
                if (stones[i][1] == stones[idx][1]) {
                    dfs(i, n, visited, stones);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), connectedComponents = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, n, visited, stones);
                connectedComponents++;
            }
        }
        return n - connectedComponents;
    }
};