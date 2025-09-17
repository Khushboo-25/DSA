class Solution {
public:
bool cyc(int i,vector<int> &vv,vector<int>&pv,vector<vector<int>>&adj,int &n)
{
    vv[i]=1;
    pv[i]=1;
    for(auto it: adj[i])
    {
        if(vv[it]==0)
        {
            if(cyc(it,vv,pv,adj,n))
            return 1;
        }
        else if(pv[it]==1)
        {
            return 1;
        }
    }
    pv[i]=0;
    return 0;
}
    bool canFinish(int n, vector<vector<int>>& ed) {
        vector<vector<int>>adj(n);
        for(auto it: ed)
        {
            int e=it[0];
            int s=it[1];
            adj[s].push_back(e);
        }
        vector<int>vv(n,0);
        for(int i=0;i<n;i++)
        {
            if(vv[i]==0)
            {
                vector<int>pv(n,0);
                if(cyc(i,vv,pv,adj,n))
                return 0;
            }
        }
        return 1;
    }
};