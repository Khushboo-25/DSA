class Solution {
public:
typedef  pair<int,pair<int,int>> ppl ;
vector<pair<int,int>>dr={{0,1},{0,-1},{1,0},{-1,0}};
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vv(n,vector<int>(m,INT_MAX));
        priority_queue<ppl,vector<ppl>,greater<ppl>>pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    pq.push({0,{i,j}});
                    vv[i][j]=0;
                }
            }
        }
        while(!pq.empty())
        {
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(auto it: dr)
            {
                int x1=x+it.first;
                int y1=y+it.second;
                if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1]==0 && vv[x1][y1]>d+1)
                {
                    vv[x1][y1]=d+1;
                    pq.push({d+1,{x1,y1}});
                }

            }
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    ans=max(ans,vv[i][j]);
                }
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};