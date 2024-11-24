class Solution {
public:
int call(int &n,int &m,int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>>&dp)
{
    if(j1>=m || j1<0 || j2>=m || j2<0)
    return 0;

    if(dp[i][j1][j2]!=-1)
    return dp[i][j1][j2];
    if(i==n-1)
    {
        if(j1==j2)
        {
           return grid[i][j1];

        }
        else
        {
            return grid[i][j1]+grid[i][j2];
        }
    }
    int ans=0;
    for(int d1=-1;d1<=1;d1++)
    {
        for(int d2=-1;d2<=1;d2++)
        {
            int v=0;
            if(j1==j2)
            {
                v+=grid[i][j1];
                
            }   
            else
            v+=grid[i][j1]+grid[i][j2];
            v+=call(n,m,i+1,j1+d1,j2+d2,grid,dp);
            ans=max(ans,v);

        }
    }
    return dp[i][j1][j2]=ans;
    

}
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        int i=0,j1=0,j2=m-1;
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
        return call(n,m,i,j1,j2,grid,dp);
        
    }
};