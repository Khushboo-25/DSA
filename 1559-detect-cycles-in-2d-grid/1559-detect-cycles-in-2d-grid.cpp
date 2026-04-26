class Solution {
public:
    vector<pair<int,int>> dr = {{0,-1},{0,1},{1,0},{-1,0}};
    
    bool call(int i, int j, int pi, int pj, int &n, int &m, 
              vector<vector<int>>& vv, vector<vector<char>>& grid, char c) 
    {
        vv[i][j] = 1;
        for (auto &d : dr) {
            int ni = i + d.first, nj = j + d.second;
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if (grid[ni][nj] != c) continue;
            
            if (ni == pi && nj == pj) continue; // skip parent
            
            if (vv[ni][nj]) return true; // cycle found
            if (call(ni, nj, i, j, n, m, vv, grid, c)) return true;
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vv(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vv[i][j] == 0) {
                    if (call(i, j, -1, -1, n, m, vv, grid, grid[i][j])) 
                        return true;
                }
            }
        }
        return false;
    }
};
