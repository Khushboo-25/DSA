class Solution {
public:
bool cycle(int i,vector<vector<int>> &graph,vector<int> &vv,vector<int> &pv)
{
    vv[i]=1;
    pv[i]=1;
    for(auto it: graph[i])
    {
        if(vv[it]==0 && cycle(it,graph,vv,pv))
        return true;
        if(vv[it]==1 && pv[it]==1)
        return true;
        
    }
    pv[i]=0;
    return 0;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        vector<int> ans;
        int n=graph.size();
        for(int i=0;i<n;i++)
        {
            vector<int> vv(n,0),pv(n,0);
            if(!cycle(i,graph,vv,pv))
            {
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};