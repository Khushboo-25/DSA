class Solution {
public:
int call(int stx,int sty,int pn,vector<vector<int>>& grid,int &n,int &m,int tn)
{
    if(grid[stx][sty]==2)
    {
        if(tn==0)
        return 1;
        return 0;
    }
    
    // if(dp[stx][sty][pn][tn]!=-1)
    // return dp[stx][sty][pn][tn];
    int ans=0;
    vector<pair<int,int>>dr={{-1,0},{0,-1},{1,0},{0,1}};
    for(auto it: dr)
    {
        int x=stx+it.first;
        int y=sty+it.second;
        if(x>=0 && y>=0 && x<n && y<m && grid[x][y]!=-1)
        {
            int pos = m * x + y;
            if ((pn & (1 << pos)) == 0 ) 
            {
                int cn = pn | (1 << pos);
                ans += call(x, y, cn, grid, n, m,tn-1);
            }
        }
    }
    return ans;
}
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        
        int stx=-1,sty=-1;
        int n=grid.size(),m=grid[0].size();
        // bool f=0;
        int tn=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    stx=i;
                    sty=j;
                }
                else if(grid[i][j]==0)
                tn++;
                
            }
            

        }
        tn++;
        int x = 1 << (m * stx + sty);
        // map<pair<pair<
        // vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int>(n*m,-1)));
        // x=update(x,stx,sty,m);
        return call(stx,sty,x,grid,n,m,tn);
        
    }
};