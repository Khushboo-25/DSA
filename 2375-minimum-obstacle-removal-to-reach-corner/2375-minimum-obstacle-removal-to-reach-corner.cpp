#define point pair<int,pair<int,int>>
vector<pair<int,int>>dr={{-1,0},{1,0},{0,1},{0,-1}};
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vv(n,vector<int>(m,INT_MAX));
        // if(grid[0][0]==1)
        // {
        //     vv[0][0]=1;
        // }
        // else 
        vv[0][0]=0;
        
        priority_queue<point,vector<point>,greater<point>>pq;
        pq.push({vv[0][0],{0,0}});
        while(!pq.empty())
        {
            auto tp=pq.top();
            int d=tp.first;
            int x=tp.second.first;
            int y=tp.second.second;
            pq.pop();
            if(vv[x][y]>d)
            continue;
            for(auto it:dr)
            {
                int x1=x+it.first;
                int y1=y+it.second;
                int d2=0;
                if(x1<n && x1>=0 && y1>=0 && y1<m)
                {
                    if(grid[x1][y1]==1)
                    d2++;
                    if(vv[x1][y1]>d+d2)
                    {
                        vv[x1][y1]=d+d2;
                        pq.push({vv[x1][y1],{x1,y1}});
                    }
                }

            }
        }
        return vv[n-1][m-1];
    }
};