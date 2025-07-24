class Solution {
public:
bool call(int sz,vector<vector<int>>&grid,int &n,int &m)
{
    // bool ans=0;
    for(int i=0;i<=n-sz;i++)
    {
        for(int j=0;j<=m-sz;j++)
        {
            bool md=1;
            for(int b=j;b<=j+sz-1;b++)
            {
                if(grid[i][b]==0|| grid[i+sz-1][b]==0)
                {
                    md=0;
                    break;
                }
            }
            for(int a = i; a < i + sz && md; a++) 
            {
                if(grid[a][j] == 0 || grid[a][j + sz - 1] == 0) 
                {
                    md= false;
                    break;
                }
            }
            if(md)
            return 1;
        }
    }
    return 0;
}
    int largest1BorderedSquare(vector<vector<int>>& grid) 
    {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        int s=1, e=min(n,m);
        
        for(int md=s;md<=e;md++)
            // int md=s+(e-s)/2;
        {
                if(call(md,grid,n,m))
            {
                ans=md;
            }
        }
        return ans*ans;
        
    }
};