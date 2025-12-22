class Solution {
public:
void call(vector<int>&topo,int i,vector<int>&vv,vector<vector<int>>&adj)
{
    vv[i]=1;
    for(auto it:adj[i])
    {
        if(vv[it]==0)
        {
            call(topo,it,vv,adj);
        }
    }
    topo.push_back(i);
}
void call2(int i,vector<int>&vv,vector<vector<int>>&adj)
{
    vv[i]=1;
    for(auto it:adj[i])
    {
        if(vv[it]==0)
        call2(it,vv,adj);
    }
}
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        vector<int>topo;
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vv(n,0);
        for(int i=0;i<n;i++)
        {
            if(vv[i]==0)
            {
                call(topo,i,vv,adj);
            }
        }
        for(auto &it:vv)
        it=0;
        vector<int>ans;
        for(auto it:topo)
        cout<<it<<" ";
        for(int i=n-1;i>=0;i--)
        {
            if(vv[topo[i]]==0)
            {
                call2(topo[i],vv,adj);
                ans.push_back(topo[i]);
            }
        }
        if(ans.size()!=1)
        return -1;
        return ans[0];
        
    }
};