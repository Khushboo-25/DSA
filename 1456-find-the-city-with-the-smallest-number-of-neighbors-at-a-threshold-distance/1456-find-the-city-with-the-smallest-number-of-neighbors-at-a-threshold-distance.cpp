class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        int ans=n,c=INT_MAX;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it: edges)
        {
            int x=it[0];
            int y=it[1];
            int w=it[2];
            adj[x].push_back({y,w});
            adj[y].push_back({x,w});
        }
        
        for(int i=n-1;i>=0;i--)
        {
            vector<int> vv(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,i});
            vv[i]=0;
            while(!pq.empty())
            {
                auto it=pq.top();
                int d=it.first;
                int node=it.second;
                pq.pop();
                if(d>dt)
                {
                    continue;
                }
                for(auto it1:adj[node])
                {
                    int n1=it1.first;
                    int d2=it1.second;
                    if(vv[n1]>d+d2)
                    {
                        vv[n1]=d+d2;
                        pq.push({d+d2,n1});
                    }
                }
            }
            int cn=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && vv[j]<=dt)
                cn++;
                
            }
            if(cn<c)
            {
                ans=i;
                c=cn;
            }
        }
        return ans;
    }
};