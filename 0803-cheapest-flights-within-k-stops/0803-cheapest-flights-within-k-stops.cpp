class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<vector<int>>> adj(n);
        for(auto it: flights)
        {
            int a=it[0];
            int b=it[1];
            int d=it[2];
            adj[a].push_back({b,d});
        }
        vector<vector<int>> vv(n, vector<int>(k + 2, INT_MAX));
        vv[src][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;
        // queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{0,src}});
        
        while(!pq.empty())
        {
            auto it=pq.top();
            int d=it.first;
            int kn=it.second.first;
            
            int node=it.second.second;
            pq.pop();
            if( node==dst)
            {
                return d;
            }
            // If we have used all allowed stops, continue
            if(kn> k)
                continue;
            
            
            for(auto it: adj[node])
            {
                int n1=it[0];
                int d2=it[1];
                if(d+d2<vv[n1][kn + 1] )
                {
                    
                    vv[n1][kn+1]=d+d2;
                    pq.push({vv[n1][kn+1],{kn+1,n1}});
                }
            }
        }
        
        return -1;
    }
};