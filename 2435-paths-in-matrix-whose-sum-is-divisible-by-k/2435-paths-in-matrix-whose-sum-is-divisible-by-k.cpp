class Solution {
public:
vector<pair<int,int>>dr={{-1,0},{0,-1}};
int mod=1e9+7;
int call(int i,int j,int rm,int &n,int &m,vector<vector<int>>&grid,int &k,vector<vector<vector<int>>>&dp)
{
    if(i==0 && j==0)
    {
        if(rm==0)
        return 1;
        return 0;
    }
    if(i<0 || j<0)
    return 0;
    if(dp[i][j][rm]!=-1)
    return dp[i][j][rm];
    int ans=0;
    for(auto it: dr)
    {
        int x=i+it.first;
        int y=j+it.second;
        if(x>=0 && y>=0)
        {
            int rm1=(rm+grid[x][y])%k;
            ans=(ans+call(x,y,rm1,n,m,grid,k,dp))%mod;
        }
    }
    return dp[i][j][rm]=ans;
}
    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return call(n-1,m-1,(grid[n-1][m-1])%k,n,m,grid,k,dp);

    }
};