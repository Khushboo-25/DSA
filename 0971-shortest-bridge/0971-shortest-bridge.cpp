class Solution {
public:
vector<pair<int,int>>dr={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(int i,int j, int &n,vector<vector<int>>&grid,int &cn,vector<vector<pair<int,int>>>&pn)
{
    pn[cn-2].push_back({i,j});
    grid[i][j]=cn;
    for(auto it: dr)
    {
        int x=i+it.first;
        int y=j+it.second;
        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1)
        {
            dfs(x,y,n,grid,cn,pn);
        }
    }

}
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<pair<int,int>>>pn(2);
        int cn=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,n,grid,cn,pn);
                    cn++;
                }
            }
        }
        int ans=INT_MAX;
        int n1=pn[0].size();
        int n2=pn[1].size();
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                int ans1=abs(pn[0][i].first-pn[1][j].first)+abs(pn[0][i].second-pn[1][j].second);
                ans=min(ans,ans1);
            }
        }
        return ans-1;
        
    }
};