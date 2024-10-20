class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times)
        {
            int x=it[0];
            int y=it[1];
            int tm=it[2];
            adj[x].push_back({y,tm});
        }
        vector<int>tt(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        tt[k]=0;
        while(!pq.empty())
        {
            auto tp=pq.top();
            int node=tp.second;
            int d=tp.first;
            pq.pop();
            for(auto it:adj[node])
            {
                int nw=it.first;
                int d2=it.second;
                if(tt[nw]>d+d2)
                {
                    tt[nw]=d+d2;
                    pq.push({tt[nw],nw});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(tt[i],ans);
        }
        if(ans==INT_MAX)
        return -1;
        return ans;

        
    }
};