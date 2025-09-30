class Solution {
public:
    int minTime(int n, vector<vector<int>>& ed) 
    {
        vector<vector<vector<int>>>adj(n);
        for(auto it: ed)
        {
            int x=it[0];
            int y=it[1];
            int st=it[2];
            int et=it[3];
            adj[x].push_back({y,st,et});
        }
        vector<int>vv(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vv[0]=0;
        while(!pq.empty())
        {
            int tm=pq.top().first;
            int x=pq.top().second;
            pq.pop();
            for(auto it:adj[x])
            {
                int y=it[0];
                int st=it[1];
                int et=it[2];
                if(tm>=st && tm<=et)
                {
                    if(vv[y]>=1+tm)
                    {
                        vv[y]=1+tm;
                        pq.push({vv[y],y});
                    }
                }
                else if(tm<st)
                {
                    if(vv[y]>st+1)
                    {
                        vv[y]=st+1;
                        pq.push({vv[y],y});
                    }
                }
            }
        }
        if(vv[n-1]==INT_MAX)
        return -1;
        return vv[n-1];
        
    }
};