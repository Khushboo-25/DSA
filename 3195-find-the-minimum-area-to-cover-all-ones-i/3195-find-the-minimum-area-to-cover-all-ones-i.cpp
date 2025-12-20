class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        unordered_map<int,bool>rr,col;
        int mnr=n-1,mxr=0,mxc=0,mnc=m-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    mxc=max(j,mxc);
                    mnc=min(j,mnc);
                    mxr=max(i,mxr);
                    mnr=min(i,mnr);
                }
            }
        }
        return (mxr-mnr+1)*(mxc-mnc+1);
        
    }
};