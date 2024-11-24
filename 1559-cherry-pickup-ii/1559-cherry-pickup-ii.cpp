class Solution {
public:
int call (int i1,int j1,int j2,vector<vector<int> > &grid,int &n,int &m,vector<vector<vector<int>>>&dp)
  {
      if(j1<=0 || j1>m ||j2<=0 ||j2>m)
      {
            return 0;
      }
      if(dp[i1][j1][j2]!=-1)
      return dp[i1][j1][j2];
      if(i1==n)
      {
          if(j1==j2)
          return grid[i1-1][j1-1];
          else
          return grid[i1-1][j1-1]+grid[i1-1][j2-1];
      }
      
      int mx=INT_MIN;
      for(int d1=-1;d1<=1;d1++)
      {
          for(int d2=-1;d2<=1;d2++)
          {
              int v=0;
              
              if(j1==j2)
              v=grid[i1-1][j1-1];
              else
              v=grid[i1-1][j1-1]+grid[i1-1][j2-1];
              v+=call(i1+1,j1+d1,j2+d2,grid,n,m,dp);
              mx=max(v,mx);
          }
      }
      return dp[i1][j1][j2]=mx;
      
      
      
  }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int i1=1,j1=1,j2=m;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(m + 1, -1)));
        return call(i1,j1,j2,grid,n,m,dp);
    }
};