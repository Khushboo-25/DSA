class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>pq;
        int pv=grid[sr][sc];
        grid[sr][sc]=color;
        pq.push({sr,sc});
        int ans=0;
        vector<pair<int,int>>dr={{1,0},{0,1},{-1,0},{0,-1}};
        while(!pq.empty())
        {
            int x=pq.front().first;
            int y=pq.front().second;
            pq.pop();
            for(auto it: dr)
            {
                int x1=x+it.first;
                int y1=y+it.second;
                if(x1>=0 && y1>=0 && x1<n && y1<m && grid[x1][y1]!=color && grid[x1][y1]==pv)
                {
                    grid[x1][y1]=color;
                    pq.push({x1,y1});
                }
            }
        }
        return grid;
    }
};