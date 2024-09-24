class Solution {
public:
    int solve(int n,int m,vector<vector<int>> &vv,vector<vector<int>>& grid)
    {
        if(m<0 || n<=0)
        return 0;
        if(grid[n-1][m-1]==1)
        return vv[n][m]=0;
        if(m==1 && n==1)
        return vv[n][m]=1;


        if(vv[n][m]!=-1)
        return vv[n][m];

        return vv[n][m]=solve(n-1,m,vv,grid)+solve(n,m-1,vv,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        if(grid[0][0]==1)
        return 0;
        int n=grid.size();
        int m=grid[0].size();
       
        vector<vector<int>> vv(n+1,vector<int>(m+1,-1));
        
        return solve(n,m,vv,grid);
    }
};