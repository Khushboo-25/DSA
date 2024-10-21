class Solution {
public:
int dfs(int i,vector<int> &vv,vector<vector<pair<int,int>>> &adj)
{
    // vv[i]=1;
    int sm=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,i});
    while(!pq.empty())
    {
        auto it=pq.top();
        int w=it.first;
        int node=it.second;
        pq.pop();
        if(vv[node]==0)
        {
            sm+=w;
            vv[node]=1;
            for(auto it1:adj[node])
            {
                int nw=it1.first;
                int w2=it1.second;
                if(vv[nw]==0)
                pq.push({w2,nw});
            }
        }
    }
    return sm;
}
    int makeConnected(int n, vector<vector<int>>& conn) 
    {
        vector<vector<pair<int,int>>> adj(n);
        int sum=0;
        for(auto it: conn)
        {
            int x=it[0];
            int y=it[1];
            sum+=1;
            adj[x].push_back({y,1});
            adj[y].push_back({x,1});

        }
        if(sum<n-1)
        return -1;
        int tm=n-1;
        vector<int> vv(n,0);
        // int cn=0;
        for(int i=0;i<n;i++)
        {
            if(vv[i]==0)
            tm-=dfs(i,vv,adj);
        }
        return tm;
        
    }
};