class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vv(n,vector<int>(m,0));
        vv[0][0]=health-grid[0][0];
        if(vv[0][0]<=0)
        return 0;
        
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({vv[0][0],{0,0}});
        vector<pair<int,int>> dr={{-1,0},{1,0},{0,-1},{0,1}};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int ch=it.first;
            int cx=it.second.first;
            int cy=it.second.second;
            if(cx==n-1 && cy==m-1)
            {
                if(vv[cx][cy]>0)
                return 1;
                return 0;
            }
            for(auto d1:dr)
            {
                int cx1=cx+d1.first;
                int cy1=cy+d1.second;
                if(cx1>=0 && cx1<n && cy1>=0 && cy1<m)
                {
                    if(vv[cx1][cy1]==0)
                    {
                        if(ch-grid[cx1][cy1]>0)
                        {
                            vv[cx1][cy1]=ch-grid[cx1][cy1];
                            pq.push({vv[cx1][cy1],{cx1,cy1}});
                        }
                    }
                }
                
                
            }
        }
        if(vv[n-1][m-1]>0)
        return 1;
        return 0;

        
    }
};