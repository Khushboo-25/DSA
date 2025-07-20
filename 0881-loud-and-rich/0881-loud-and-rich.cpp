class Solution {
public:
void update(vector<int> &vv,int i,int &n,vector<vector<int>> &adj,vector<int> &qt)
{
    vv[i]=qt[i];
    for(auto it: adj[i])
    {
        if(vv[it]==-1)
        update(vv,it,n,adj,qt);
        vv[i]=min(vv[i],vv[it]);
    }
}
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& qt) 
    {
        int n=qt.size();
        vector<int> ans(n,n+1);
        vector<vector<int>>adj(n);
        for(auto it: richer)
        {
            int x=it[0];
            int y=it[1];
            adj[y].push_back(x);
        }
        unordered_map<int,int>pp;
        for(int i=0;i<n;i++)
        {
            pp[qt[i]]=i;
        }
        vector<int> vv(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vv[i]==-1)
            {
                update(vv,i,n,adj,qt);
            }
        }
        for(int i=0;i<n;i++)
        {
            vv[i]=pp[vv[i]];
        }
        return vv;
        
    }
};