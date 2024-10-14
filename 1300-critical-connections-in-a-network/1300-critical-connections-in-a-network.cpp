class Solution {
public:
int time=1;
void dfs(int node,int p,vector<int> &vv,int ta[],int low[],vector<vector<int>> &adj, vector<vector<int>> &bridges)
{
    vv[node]=1;
    ta[node]=time;
    low[node]=time;
    time++;
    for(auto it:adj[node])
    {
        if(it==p)
        {
            continue;
        }
        else if(vv[it]==1)
        {
            low[node]=min({low[it],low[node]});
        }
        else
        {
            dfs(it,node,vv,ta,low,adj,bridges);
            low[node]=min({low[it],low[node]});
            if(low[it]>ta[node])
            {
                bridges.push_back({it,node});
            }
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        vector<vector<int>> adj(n);
        for(auto it:conn)
        {
            adj[it[1]].push_back(it[0]);
            adj[it[0]].push_back(it[1]);

        }
        vector<int> vv(n,0);
        int ta[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0,-1,vv,ta,low,adj,bridges);
        return bridges;
    }
};