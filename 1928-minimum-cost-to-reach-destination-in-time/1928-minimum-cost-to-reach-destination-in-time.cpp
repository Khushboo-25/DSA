class Solution {
public:
typedef pair<int,pair<int,int>> pn;

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& nodecost)
    {
        int n=nodecost.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges)
        {
            int x=it[0];
            int y=it[1];
            int time=it[2];
            adj[x].push_back({y,time});
            adj[y].push_back({x,time});
        }
        priority_queue<pn,vector<pn>,greater<pn>>pq;
        // {cost, {time ,node}}
        
        
        vector<int>vv(n,INT_MAX);
        vector<int>tt(n,INT_MAX);
        tt[0]=0;
        vv[0]=nodecost[0];
        pq.push({nodecost[0],{tt[0],0}});
        while(!pq.empty())
        {
            int ccost=pq.top().first;
            int ctime=pq.top().second.first;
            int node=pq.top().second.second;
            pq.pop();

            for(auto it:adj[node])
            {
                int nei=it.first;
                int time=it.second;
                if( time+ctime<=maxTime)
                {
                    if(ccost+nodecost[nei]<vv[nei])
                    {
                        vv[nei]=ccost+nodecost[nei];
                        tt[nei]=ctime+time;
                        pq.push({vv[nei],{tt[nei],nei}});
                        
                    }
                    if(time+ctime<tt[nei])
                    {
                        tt[nei]=time+ctime;
                        pq.push({ccost+nodecost[nei],{tt[nei],nei}});
                        
                    }
                    
                    
                }
            }
        }
        if(vv[n-1]==INT_MAX)
        vv[n-1]=-1;
        return vv[n-1];
        
    }
};