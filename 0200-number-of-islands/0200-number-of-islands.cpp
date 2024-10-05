class Solution {
public:
void bfs(int i,int j,vector<vector<int>> &vv,vector<vector<char>>& grid,int n,int m)
{
    queue<pair<int,int>>pq;
    pq.push({i,j});
    vv[i][j]=1;
    vector<pair<int,int>>dr={{-1,0},{1,0},{0,1},{0,-1}};
    while(!pq.empty())
    {
        int x=pq.front().first;
        int y=pq.front().second;
        pq.pop();
        for(auto it: dr)
        {
            int x1=x+it.first;
            int y1=y+it.second;
            if(x1>=0 && x1<n && y1>=0 && y1<m && vv[x1][y1]==0 && grid[x1][y1]=='1')
            {
                vv[x1][y1]=1;
                pq.push({x1,y1});
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vv(n,vector<int>(m,0));
        int cn=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vv[i][j]==0 && grid[i][j]=='1')
                {
                    bfs(i,j,vv,grid,n,m);
                    cn++;
                }
            }
        }
        return cn;
    }
};