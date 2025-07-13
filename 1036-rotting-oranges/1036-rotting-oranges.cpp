class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // int t=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    pq.push({{i,j},0});
                }
            }
        }
        int ans=0;
        vector<pair<int,int>>dr={{1,0},{0,1},{-1,0},{0,-1}};
        while(!pq.empty())
        {
            int x=pq.front().first.first;
            int y=pq.front().first.second;
            int t1=pq.front().second;
            ans=max(ans,t1);
            pq.pop();
            for(auto it: dr)
            {
                int x1=x+it.first;
                int y1=y+it.second;
                if(x1>=0 && y1>=0 && x1<n && y1<m && grid[x1][y1]==1)
                {
                    grid[x1][y1]=2;
                    pq.push({{x1,y1},t1+1});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                return -1;
            }
        }
        return ans;
        
    }
};