class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& mv) 
    {
        int n=grid.size(),m=grid[0].size();

        vector<int>dp(m,0);
        for(int i=0;i<m;i++)
        {
            dp[i]=grid[0][i];
        }
        for(int i=1;i<n;i++)
        {
            vector<int>dp1(m,INT_MAX);
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    int s=grid[i-1][k];
                    dp1[j]=min(dp1[j],dp[k]+grid[i][j]+mv[s][j]);
                }
            }
            dp=dp1;
        }
        return *min_element(dp.begin(),dp.end());
    
        
    }
};