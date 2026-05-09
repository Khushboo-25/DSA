class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size();
        int m = grid[0].size();

        int layers = min(n, m) / 2;

        for(int layer = 0; layer < layers; layer++)
        {
            vector<int> v;

            int top = layer;
            int left = layer;
            int bottom = n - layer - 1;
            int right = m - layer - 1;

            // top row
            for(int j = left; j <= right; j++)
                v.push_back(grid[top][j]);

            // right col
            for(int i = top + 1; i <= bottom - 1; i++)
                v.push_back(grid[i][right]);

            // bottom row
            for(int j = right; j >= left; j--)
                v.push_back(grid[bottom][j]);

            // left col
            for(int i = bottom - 1; i >= top + 1; i--)
                v.push_back(grid[i][left]);

            int sz = v.size();
            int rot = k % sz;

            vector<int> r(sz);

            for(int i = 0; i < sz; i++)
            {
                r[i] = v[(i + rot) % sz];
            }

            int idx = 0;

            // put back top row
            for(int j = left; j <= right; j++)
                grid[top][j] = r[idx++];

            // right col
            for(int i = top + 1; i <= bottom - 1; i++)
                grid[i][right] = r[idx++];

            // bottom row
            for(int j = right; j >= left; j--)
                grid[bottom][j] = r[idx++];

            // left col
            for(int i = bottom - 1; i >= top + 1; i--)
                grid[i][left] = r[idx++];
        }

        return grid;
    }
};