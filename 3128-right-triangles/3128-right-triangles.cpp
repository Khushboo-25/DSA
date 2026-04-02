class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>up(n,vector<int>(m,0));
        vector<vector<int>>down(n,vector<int>(m,0));
        vector<vector<int>>right(n,vector<int>(m,0));
        vector<vector<int>>left(n,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            up[0][i]=grid[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                up[i][j]=up[i-1][j]+grid[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            down[n-1][i]=grid[n-1][i];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                down[i][j]=down[i+1][j]+grid[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            right[i][m-1]=grid[i][m-1];
        }
        for(int j=m-2;j>=0;j--)
        {
            for(int i=0;i<n;i++)
            {
                right[i][j]=right[i][j+1]+grid[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            left[i][0]=grid[i][0];
        }
        for(int j=1;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                left[i][j]=left[i][j-1]+grid[i][j];
            }
        }
        long long ans=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(grid[i][j]==1)
                {
                if(i+1<n && j+1<m)
                ans+=down[i+1][j]*1ll*right[i][j+1];
                if(i-1>=0 && j+1<m)
                ans+=up[i-1][j]*1ll*right[i][j+1];
                if(i-1>=0 && j-1>=0)
                ans+=up[i-1][j]*1ll*left[i][j-1];
                if(i+1<n && j-1>=0)
                ans+=down[i+1][j]*1ll*left[i][j-1];
                }
                
            }
        }
        return ans;
        
    }
};