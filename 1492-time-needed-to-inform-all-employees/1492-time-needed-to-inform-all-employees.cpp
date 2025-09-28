class Solution {
public:
    int numOfMinutes(int n, int id, vector<int>& mg, vector<int>& tm) 
    {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>vv(n,INT_MAX);
        for(int i=0;i<n;i++)
        {
            if(mg[i]!=-1)
            adj[mg[i]].push_back({i,tm[i]});
            else
            {
                vv[i]=tm[i];
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({tm[id],id});
        while(!pq.empty())
        {
            int time=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it: adj[node])
            {
                int node1=it.first;
                int time1=it.second;
                if(vv[node1]>time+time1)
                {
                    vv[node1]=time+time1;
                    pq.push({vv[node1],node1});
                }
            }
        }
        int ans=0;
        for(auto it:vv)
        {
            ans=max(ans,it);
        }
        return ans;
    }
};