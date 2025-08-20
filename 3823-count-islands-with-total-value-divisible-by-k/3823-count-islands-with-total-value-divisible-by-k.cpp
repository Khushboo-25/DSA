
typedef long long ll;
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int count = 0;

    vector<pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j] > 0 && !visited[i][j]) {
                // start DFS
                stack<pair<int,int>> stk;
                stk.push({i,j});
                visited[i][j] = true;
                ll sum = 0;

                while(!stk.empty()) {
                    auto [x, y] = stk.top(); stk.pop();
                    sum += grid[x][y];

                    for(auto [dx, dy] : directions) {
                        int nx = x + dx, ny = y + dy;
                        if(nx >= 0 && ny >= 0 && nx < m && ny < n &&
                           grid[nx][ny] > 0 && !visited[nx][ny]) {
                            visited[nx][ny] = true;
                            stk.push({nx, ny});
                        }
                    }
                }

                if(sum % k == 0) ++count;
            }
        }
    }

    return count;
    }
};