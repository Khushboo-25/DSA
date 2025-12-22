class Solution {
public:
    int findChampion(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<int>in(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && grid[i][j]==1)
                {
                    in[j]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            return i;
        }
        return -1;
        
    }
};