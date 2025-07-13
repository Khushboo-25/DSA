class Solution {
public:
bool cy(int i,vector<vector<int>>&adj,vector<int> &vv,vector<int>&pv)
{
    vv[i]=1;
    pv[i]=1;
    for(auto it: adj[i])
    {
        if(pv[it]==1)
        return 1;
        if(vv[it]==0 && cy(it,adj,vv,pv))
        return 1;
    }
    pv[i]=0;
    return 0;
}
    bool canFinish(int n, vector<vector<int>>& edge) {
        vector<vector<int>>adj(n);

        for(auto it: edge)
        {
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
        }
        
        for(int i=0;i<n;i++)
        {
            vector<int>vv(n,0),pv(n,0);
            if(cy(i,adj,vv,pv))
            return 0;
        }
        return 1;
    }
};