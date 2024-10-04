class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto it: edges)
        {
            int x=it[0];
            int y=it[1];
            int w=it[2];
            adj[x].push_back({y,w});
            adj[y].push_back({x,w});
        }
        vector<int> vv(n,INT_MAX);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vv[0]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            int d=it.first;
            int node=it.second;
            pq.pop();
            if(d>=disappear[node] || d>vv[node])
            continue;
            for(auto it: adj[node])
            {
                int n1=it.first;
                int d2=it.second;
                if(d+d2<disappear[n1] && d+d2<vv[n1])
                {
                    vv[n1]=d+d2;
                    pq.push({vv[n1],n1});
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vv[i]==INT_MAX)
            vv[i]=-1;
        }
        return vv;
    }
};