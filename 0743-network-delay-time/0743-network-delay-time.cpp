class Solution {
public:
typedef pair<int,int> pl;
    int networkDelayTime(vector<vector<int>>& tm, int n, int k) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:tm)
        {
            int x=it[0]-1,y=it[1]-1,wt=it[2];
            adj[x].push_back({y,wt});
        }
        vector<int>dis(n,INT_MAX);
        priority_queue<pl,vector<pl>,greater<pl>>pq;
        dis[k-1]=0;
        pq.push({0,k-1});
        while(!pq.empty())
        {
            int d=pq.top().first;
            int x=pq.top().second;
            pq.pop();
            for(auto it:adj[x])
            {
                int x1=it.first;
                int d1=it.second;
                if(dis[x1]>d+d1)
                {
                    dis[x1]=d+d1;
                    pq.push({d+d1,x1});
                }
            }
        }
        int ans=*max_element(dis.begin(),dis.end());
        if(ans==INT_MAX)
        return -1;
        return ans;
        
    }
};