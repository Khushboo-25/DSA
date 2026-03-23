typedef pair<int,pair<int,int>> pl;
class Solution {
public:
vector<pair<int,int>>dr={{-1,0},{0,-1},{1,0},{0,1}};
    int minimumEffortPath(vector<vector<int>>& ht) 
    {
        int n=ht.size(),m=ht[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        priority_queue<pl,vector<pl>,greater<pl>>pq;
        dis[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            if(x==n-1 && y==m-1)
            return d;
            pq.pop();
            for(auto it:dr)
            {
                int x1=x+it.first;
                int y1=y+it.second;
                if(x1>=0 && x1<n && y1>=0 && y1<m)
                {
                    int d1=max(d,abs(ht[x1][y1]-ht[x][y]));
                    if(d1<dis[x1][y1])
                    {
                        dis[x1][y1]=d1;
                        pq.push({d1,{x1,y1}});
                    }
                }
            }
        }
        if(dis[n-1][m-1]==INT_MAX)
        return -1;
        return dis[n-1][m-1];
    }
};