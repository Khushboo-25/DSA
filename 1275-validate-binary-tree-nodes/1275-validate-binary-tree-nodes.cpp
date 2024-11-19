class Solution {
public:
bool dfs(int i,int p,vector<vector<int>> &adj,vector<int> &vv)
{
    vv[i]=1;
    for(auto it:adj[i])
    {
        if(vv[it]==0)
        {
            if(dfs(it,i,adj,vv))
            {
                return 1;
            }
        }
        else
        {
            if(it!=p)
            return 1;
            
        }
    }
    return 0;
}
    bool validateBinaryTreeNodes(int n, vector<int>& lf, vector<int>& rf) 
    {
        vector<int> in(n,0),out(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            if(lf[i]!=-1)
            {
                adj[i].push_back(lf[i]);
                in[lf[i]]++;
                out[i]++;
                adj[lf[i]].push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(rf[i]!=-1)
            {
                in[rf[i]]++;
                out[i]++;
                adj[i].push_back(rf[i]);
                adj[rf[i]].push_back(i);
            }
        }
        vector<int>vv(n,0);
        if(dfs(0,-1,adj,vv))
        return 0;
        for(int i=0;i<n;i++)
        {
            if(vv[i]==0 )
            return 0;
            if(in[i]>1)
            return 0;

        }
        return 1;

        
        

        
    }
};