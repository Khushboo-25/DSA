class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<int>rw(n,0);
        vector<int>cc(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    rw[i]++;
                    cc[j]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int rw1=rw[i];
                int rw0=n-rw[i];
                int cc1=cc[j];
                int cc0=m-cc[j];
                grid[i][j]=rw1+cc1-rw0-cc0;

            }
        }
        return grid;
        
    }
};