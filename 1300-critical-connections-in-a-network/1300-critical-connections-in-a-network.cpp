class Solution {
public:
int time=1;
void dfs(int i,int p,vector<int> &vv,vector<int> &ta,vector<int> &low,vector<vector<int>> &adj,vector<vector<int>>&ans)
{
    vv[i]=1;
    ta[i]=time;
    low[i]=time;
    time++;
    for(auto it: adj[i])
    {
        if(it==p)
        continue;
        else if(vv[it]==1)
        low[i]=min(low[i],ta[it]);
        else{
            dfs(it,i,vv,ta,low,adj,ans);
            low[i]=min(low[i],low[it]);
            if(ta[i]<low[it])
            ans.push_back({i,it});
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) 
    {
        vector<vector<int>> adj(n);
        for(auto it: conn)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vv(n,0),ta(n,0),low(n,0);
        vector<vector<int>> ans;
        dfs(0,-1,vv,ta,low,adj,ans);
        return ans;
        
    }
};