typedef pair<int,pair<int,int>> pl;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>&ed, int src, int dst, int k) 
    {
        k++;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:ed)
        {
            int x=it[0];
            int y=it[1];
            int wt=it[2];
            adj[x].push_back({wt,y});
        }
        vector<vector<int>>dis(n+1,vector<int>(k+1,INT_MAX));
        priority_queue<pl,vector<pl>,greater<pl>>pq;
        pq.push({0,{0,src}});
        dis[src][0]=0;
        while(!pq.empty())
        {
            int d=pq.top().first;
            int kt=pq.top().second.first;
            int x=pq.top().second.second;
            pq.pop();
            if(x==dst)
            return d;
            for(auto it:adj[x])
            {
                int x1=it.second;
                int d1=it.first;
                if(kt+1<=k && dis[x1][kt+1]>d+d1)
                {
                    dis[x1][kt+1]=d+d1;
                    pq.push({d+d1,{kt+1,x1}});
                }
            }
        }
        
        return -1;
        
    }
};