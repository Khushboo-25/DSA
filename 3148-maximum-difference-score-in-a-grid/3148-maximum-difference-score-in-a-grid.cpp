class Solution {
public:
    int maxScore(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>mn(n+1,vector<int>(m+1,INT_MIN));
        for(int j=m-1;j>=0;j--)
        {
            for(int i=n-1;i>=0;i--)
            {
                mn[i][j]=max({grid[i][j],mn[i+1][j],mn[i][j+1]});
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i+1<n)
                {
                    ans=max(ans,mn[i+1][j]-grid[i][j]);
                }
                if(j+1<m)
                ans=max(ans,mn[i][j+1]-grid[i][j]);
                // cout<<mn[i][j]<<" ";
            }
            cout<<endl;
        }
        // if(ans==0)
        // return -1;
        return ans;
    }
};