class Solution {
public:
bool bfs(int i,vector<vector<int>>&adj,vector<int>&vv)
{
    vv[i]=1;
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        int nw=q.front();
        q.pop();
        for(auto it:adj[nw])
        {
            if(vv[it]==-1)
            {
                vv[it]=1-vv[nw];
                q.push(it);
            }
            else if(vv[it]==vv[nw])
            return 0;
        }
    }
    return 1;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) 
    {
        vector<vector<int>>adj(n);
        for(auto it:dislikes)
        {
            int x=it[0],y=it[1];
            x--,y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> vv(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vv[i]==-1 && !bfs(i,adj,vv))
            {
                return 0;
            }
        }
        return 1;
    }
};