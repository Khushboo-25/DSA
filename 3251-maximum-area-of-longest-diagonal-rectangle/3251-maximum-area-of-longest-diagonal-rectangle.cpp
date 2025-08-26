class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dm) 
    {
        int dx=0;
        int ans=0;
        for(auto it: dm)
        {
            int x=it[0];
            int y=it[1];
            int d=(x*x+y*y);
            if(d>dx)
            {
                ans=x*y;
                dx=d;
            }
            else if(d==dx)
            {
                ans=max(ans,x*y);
            }
        }
        return ans;
        
    }
};