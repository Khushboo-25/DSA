#define pl pair<int,int>
// #define ppl pair<pair<int,int>,int>
#define plp pair<int,pair<int,int>>
vector<pair<int,int>> dr={{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
public:

    int minCost(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        map<pl,vector<plp>>adj;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int d=0;d<4;d++)
                {
                    int x1=i+dr[d].first;
                    int y1=j+dr[d].second;
                    if(x1<n && x1>=0 && y1<m && y1>=0)
                    {
                        if(grid[i][j]==d+1)
                        {
                            adj[{i,j}].push_back({0,{x1,y1}});
                        }
                        else
                        adj[{i,j}].push_back({1,{x1,y1}});
                    }
                }
            }
        }
        priority_queue<plp,vector<plp>,greater<plp>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>>vv(n,vector<int>(m,INT_MAX));
        vv[0][0]=0;
        while(!pq.empty())
        {
            auto tp=pq.top();
            pq.pop();
            int d=tp.first;
            int x=tp.second.first;
            int y=tp.second.second;
            if(vv[x][y]<d)
            continue;
            for(auto it1:adj[{x,y}])
            {
                int d2=it1.first;
                int x1=it1.second.first;
                int y1=it1.second.second;
                if(vv[x1][y1]>d+d2)
                {
                    vv[x1][y1]=d+d2;
                    pq.push({vv[x1][y1],{x1,y1}});
                }

            }
        }
        if(vv[n-1][m-1]==INT_MAX)
        return -1;
        return vv[n-1][m-1];


        
    }
};