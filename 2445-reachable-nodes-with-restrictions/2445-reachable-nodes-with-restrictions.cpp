class Solution {
public:
void call(int i,vector<vector<int>>&adj,vector<bool>&r1,vector<bool>&vv,unordered_map<int,bool>&pp)
{
    vv[i]=1;
    r1[i]=1;
    for(auto it:adj[i])
    {
        if(vv[it]==0)
        {
            if(pp[it]==0)
            {
                call(it,adj,r1,vv,pp);
            }
            else
            vv[it]=1;
        }
    }
}
    int reachableNodes(int n, vector<vector<int>>& ed, vector<int>& rt) 
    {
        unordered_map<int,bool>pp;
        for(auto it:rt)
        pp[it]=1;
        vector<vector<int>>adj(n);
        for(auto it:ed)
        {
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool>r1(n,0);
        vector<bool>vv(n,0);
        call(0,adj,r1,vv,pp);
        int cn=0;
        for(int i=0;i<n;i++)
        {
            if(r1[i]==1)
            cn++;
        }
        return cn;
    }
};