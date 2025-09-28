class Solution {
public:
vector<pair<int,int>>dr={{-1,0},{1,0},{0,1},{0,-1}};
void bfs(int i,int j,int &n,int &m,vector<vector<int>>&grid)
{
    queue<pair<int,int>>qt;
    qt.push({i,j});
    grid[i][j]=1;
    while(!qt.empty())
    {
        int x=qt.front().first;
        int y=qt.front().second;
        qt.pop();
        for(auto it:dr)
        {
            int x1=x+it.first;
            int y1=y+it.second;
            if(x1<n && x1>=0 && y1>=0 && y1<m && grid[x1][y1]==0)
            {
                grid[x1][y1]=1;
                qt.push({x1,y1});
            }
        }
    }
}
    int closedIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==0)
            {
                bfs(0,i,n,m,grid);
            }
            if(grid[n-1][i]==0)
            {
                bfs(n-1,i,n,m,grid);
            }
        }
        for(int i=1;i<n-1;i++)
        {
            if(grid[i][0]==0)
            {
                bfs(i,0,n,m,grid);
            }
            if(grid[i][m-1]==0)
            {
                bfs(i,m-1,n,m,grid);
            }
        }
        int cn=0;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(grid[i][j]==0)
                {
                    cn++;
                    bfs(i,j,n,m,grid);
                }
            }
        }
        return cn;
        
    }
};