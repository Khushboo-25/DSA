class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int cn0=0;
        for(auto it:grid)
        {
            for(auto it1:it)
            {
                if(it1==0)
                cn0++;
            }
        }
        int sx=0,sy=0;
        while(sx<n && sy<n)
        {
            if(grid[sx][sy]==0)
            return 0;
            sx++;
            sy++;
        }
        sx=0,sy=n-1;
        while(sx<n && sy>=0)
        {
            if(grid[sx][sy]==0)
            return 0;
            sx++;
            sy--;
        }

        if(cn0!=(n*n-2*n+n%2))
        {
            return 0;
        }
        return 1;
        
    }
};