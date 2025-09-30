class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) 
    {
        if(grid[0][0]!=0)
        return 0;
        map<pair<int,int>,bool>pp;
        pp[{1,2}]=1;
        pp[{2,1}]=1;
        pp[{-1,2}]=1;
        pp[{2,-1}]=1;
        pp[{1,-2}]=1;
        pp[{-2,1}]=1;
        pp[{-1,-2}]=1;
        pp[{-2,-1}]=1;
        int n=grid.size();
        unordered_map<int,pair<int,int>>p1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {

                p1[grid[i][j]]={i,j};
            }
        }
        int cn=1;
        while(cn<n*n)
        {
            int dx=p1[cn].first-p1[cn-1].first;
            int dy=p1[cn].second-p1[cn-1].second;
            if(pp[{dx,dy}]!=1)
            return 0;
            cn++;
        }
        return 1;
        
    }
};