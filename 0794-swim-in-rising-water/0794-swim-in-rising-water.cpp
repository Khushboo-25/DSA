class Solution {
public:
typedef pair<int,pair<int,int>> ppl;
vector<pair<int,int>>dr={{-1,0},{0,-1},{1,0},{0,1}};
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<int>>vv(n,vector<int>(n,INT_MAX));
        priority_queue<ppl,vector<ppl>,greater<ppl>>pq;
        pq.push({grid[0][0],{0,0}});
        
        vv[0][0]=grid[0][0];
        while(!pq.empty())
        {
            int tm=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(auto it: dr)
            {
                int x1=x+it.first;
                int y1=y+it.second;
                if(x1>=0 && x1<n && y1<n && y1>=0 )
                {
                    int tm1=max(tm,grid[x1][y1]);
                    if(tm1<vv[x1][y1])
                    {
                        vv[x1][y1]=tm1;
                        pq.push({tm1,{x1,y1}});
                    }
                }
            }
        }
        return vv[n-1][n-1];
    }
};