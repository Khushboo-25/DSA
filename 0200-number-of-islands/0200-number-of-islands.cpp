class Solution {
public:
vector<pair<int,int>>dr={{-1,0},{1,0},{0,-1},{0,1}};
void call(int i,int j,int &n,int &m,vector<vector<char>>&grid,vector<vector<bool>>&vv)
{
    vv[i][j]=1;
    for(auto it:dr)
    {
        int x=i+it.first;
        int y=j+it.second;
        if(x<n && x>=0 && y>=0 && y<m && vv[x][y]==0 && grid[x][y]=='1')
        {
            call(x,y,n,m,grid,vv);
        }
    }
}
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>>vv(n,vector<bool>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vv[i][j]==0 && grid[i][j]=='1')
                {
                    ans++;
                    call(i,j,n,m,grid,vv);
                }
            }
        }
        return ans;

        
    }
};