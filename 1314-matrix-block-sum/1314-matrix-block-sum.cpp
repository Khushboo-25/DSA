class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        int n=mat.size(),m=mat[0].size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+mat[i-1][j-1]-dp[i-1][j-1];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mxi=min(i+k+1,n);
                int mxj=min(j+k+1,m);
                int mni=max(i-k,0);
                int mnj=max(j-k,0);
                mat[i][j]=dp[mxi][mxj]-dp[mxi][mnj]-dp[mni][mxj]+dp[mni][mnj];
            }
        }
        return mat;
    }
};