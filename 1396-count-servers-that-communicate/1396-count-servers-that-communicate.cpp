class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> rn(n,0);
        vector<int> cm(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    rn[i]++;
                    cm[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && (rn[i]>1 ||cm[j]>1))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};