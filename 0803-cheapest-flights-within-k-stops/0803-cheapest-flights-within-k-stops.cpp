#define point pair<int,pair<int,int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it: flights)
        {
            int x=it[0];
            int y=it[1];
            int p=it[2];
            adj[x].push_back({y,p});
        }
        vector<vector<int>> pr(n,vector<int>(k+2,INT_MAX));
        pr[src][0]=0;
        priority_queue<point,vector<point>,greater<point>>pq;
        pq.push({0,{0,src}});
        while(!pq.empty())
        {
            auto it=pq.top();
            int tm=it.first;
            int km=it.second.first;
            int node=it.second.second;
            pq.pop();
            if(node==dst)
            return tm;
            if(km>k)
            continue;
            for(auto it: adj[node])
            {
                int nw=it.first;
                int tm2=it.second;
                if(pr[nw][km+1]>tm+tm2)
                {
                    pr[nw][km+1]=tm+tm2;
                    pq.push({pr[nw][km+1],{km+1,nw}});
                }
            }
        }
        
        return -1;

        
    }
};