class Solution {
public:
vector<pair<int,int>> dr={{-1,0},{0,-1},{0,1},{1,0}};
void dfs(int i,int j,int &m,int &n,vector<vector<int>>& grid,vector<vector<int>>&vv,int &cn1)
{
    queue<pair<int,int>>pq;
    pq.push({i,j});
    vv[i][j]=1;
    cn1++;
    while(!pq.empty())
    {
        auto it= pq.front();
        int x=it.first;
        int y=it.second;
        pq.pop();
        for(auto it1:dr)
        {
            int x1=x+it1.first;
            int y1=y+it1.second;
            if(x1<m && x1>=0 && y1<n && y1>=0 && grid[x1][y1]==1 && vv[x1][y1]==0)
            {
                pq.push({x1,y1});
                cn1++;
                vv[x1][y1]=1;
            }
        }
    }

}
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vv(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vv[i][j]==0 && grid[i][j]==1)
                {
                    int cn1=0;
                    dfs(i,j,m,n,grid,vv,cn1);
                    ans=max(ans,cn1);
                    vv[i][j]=1;
                }
            }
        }
        return ans;
        
    }
};