class Solution {
public:
vector<pair<int,int>>dr={{0,1},{0,-1},{1,0},{-1,0}};
int call(int i,int j,int &n,int &m,vector<vector<int>>&grid,vector<vector<int>>&vv)
{
    int sum=grid[i][j];
    vv[i][j]=1;
    for(auto it: dr)
    {
        int x=i+it.first;
        int y=j+it.second;
        if(x>=0 && x<n && y>=0 && y<m && vv[x][y]==0 && grid[x][y]!=0)
        {
            sum+=call(x,y,n,m,grid,vv);
        }
    }
    return sum;
}
    int findMaxFish(vector<vector<int>>& grid) 
    {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vv(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vv[i][j]==0 && grid[i][j]!=0)
                {
                    int sum=call(i,j,n,m,grid,vv);
                    ans=max(ans,sum);
                }
            }
        }
        return ans;
        
    }
};