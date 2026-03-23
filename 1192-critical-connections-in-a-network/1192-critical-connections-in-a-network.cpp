class Solution {
public:
int tm;
void call(int p,int i,vector<vector<int>>&adj,vector<int>&vv,vector<int>&st,vector<int>&mn,vector<vector<int>>&ans)
{
    vv[i]=1;
    st[i]=mn[i]=tm;
    tm++;
    for(auto it:adj[i])
    {
        if(it!=p)
        {
            if(vv[it]==1)
            {
                mn[i]=min(mn[it],mn[i]);
            }
            else
            {
                call(i,it,adj,vv,st,mn,ans);
                mn[i]=min(mn[i],mn[it]);
                if(st[i]<mn[it])
                {
                    ans.push_back({i,it});
                }
            }
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>&ed) 
    {
        vector<vector<int>>adj(n);
        for(auto it:ed)
        {
            int x=it[0],y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        tm=0;
        vector<int>vv(n,0),st(n,0),mn(n,0);
        
        vector<vector<int>>ans;
        call(-1,0,adj,vv,st,mn,ans);
        return ans;
        
    }
};