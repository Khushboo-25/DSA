class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<long long>>dn(n,vector<long long>(m,0));
        for(int i=0;i<m;i++)
        dn[0][i]=grid[0][i];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            dn[i][j]=dn[i-1][j]+grid[i][j];
        }
        vector<vector<long long>>rt(n,vector<long long>(m,0));
        for(int i=0;i<n;i++)
        rt[i][0]=grid[i][0];
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            rt[j][i]=rt[j][i-1]+grid[j][i];
        }
        for(int i=0;i<n-1;i++)
        {
            long long sm=0,sm1=0;
            for(int j=0;j<m;j++)
            {
                sm+=dn[i][j];
                sm1+=dn[n-1][j]-dn[i][j];
            }
            if(sm==sm1)
            return 1;
        }
        for(int i=0;i<m-1;i++)
        {
            long long sm=0,sm1=0;
            for(int j=0;j<n;j++)
            {
                sm+=rt[j][i];
                sm1+=rt[j][m-1]-rt[j][i];
            }
            if(sm==sm1)
            return 1;
        }
        return 0;


        
    }
};