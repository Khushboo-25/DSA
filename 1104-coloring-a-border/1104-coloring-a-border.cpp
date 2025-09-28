class Solution {
public:
vector<pair<int,int>>dr={{1,0},{-1,0},{0,1},{0,-1}};
void dfs(int i,int j,int &n,int &m,vector<vector<int>>&grid,int clr)
{
    grid[i][j]=-1;
    // vv[i][j]=-1;
    for(auto it: dr)
    {
        int x=i+it.first;
        int y=j+it.second;
        if(x<n && x>=0 && y>=0 && y<m && grid[x][y]==clr)
        {
            dfs(x,y,n,m,grid,clr);
        }
    }
}
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int rw, int cl, int clr) 
    {
        int n=grid.size();
        int cl1=grid[rw][cl];
        int m=grid[0].size();
        vector<vector<int>>vv(n,vector<int>(m,-1));
        
        dfs(rw,cl,n,m,grid,cl1);
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        for(int i=1;i<n-1;i++)
        {
            for(int j=1;j<m-1;j++)
            {
                if(grid[i][j]==-1)
                {
                    bool br=0;
                    for(auto it:dr)
                    {
                        int x=i+it.first;
                        int y=j+it.second;
                        if(grid[x][y]!=-1)
                        {
                            br=1;
                            break;
                        }
                    }
                    if(br==0)
                    {
                        vv[i][j]=0;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==-1)
                {
                    if(vv[i][j]==-1)
                    {
                        grid[i][j]=clr;
                    }
                    else
                    {
                        grid[i][j]=cl1;
                    }
                }
                
            }
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         cout<<vv[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return grid;
        
    }
};