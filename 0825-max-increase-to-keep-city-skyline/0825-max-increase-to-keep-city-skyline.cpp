class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<int>rr(n,INT_MIN),cc(n,INT_MIN);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                rr[i]=max(rr[i],grid[i][j]);
                cc[j]=max(cc[j],grid[i][j]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=min(rr[i],cc[j])-grid[i][j];
            }
        }
        return ans;
    }
};