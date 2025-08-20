class Solution {
public:
vector<vector<int>>dr={{0,-1},{-1,0},{0,1},{1,0}};
int bfs(int i,int j,vector<vector<int>>&vv,vector<vector<int>>&grid,int &n,int&m,int &k)
{
    int s=0;
    queue<pair<int,int>>pq;
    pq.push({i,j});

    vv[i][j]=1;
    while(!pq.empty())
    {
        int x=pq.front().first;
        int y=pq.front().second;
        s=(s+grid[x][y])%k;
        pq.pop();
        for(auto it: dr)
        {
            int x1=x+it[0];
            int y1=y+it[1];
            if(x1<n && x1>=0 && y1<m && y1>=0 &&vv[x1][y1]==0 && grid[x1][y1]!=0)
            {
                pq.push({x1,y1});
                vv[x1][y1]=1;
            }
        }
    }
    return s;
}
    int countIslands(vector<vector<int>>& grid, int k) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vv(n,vector<int>(m,0));
        int cn=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vv[i][j]==0 && grid[i][j]!=0)
                {
                    int s=bfs(i,j,vv,grid,n,m,k);
                    if(s%k==0)
                    {
                        cn++;
                    }
                }
            }
        }
        return cn;
    }
};