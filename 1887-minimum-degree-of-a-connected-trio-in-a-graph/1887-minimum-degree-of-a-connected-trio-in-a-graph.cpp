class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n);
        vector<vector<int>>pp(n,vector<int>(n,0));
        for(auto it:edges)
        {
            int x=it[0];
            int y=it[1];
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
            pp[x-1][y-1]=1;
            pp[y-1][x-1]=1;
        }
        int ans=INT_MAX;
        vector<int>vv(n);
        for(int i=0;i<n;i++)
        {
            vector<int>f;
            for(auto it: adj[i])
            {
                f.push_back(it);
            }
            int n1=f.size();
            for(int j=0;j<n1;j++)
            {
                // if(adj[f[j]].size()<2)
                // continue;
                for(int k=j+1;k<n1;k++)
                {
                //     if(adj[f[k]].size()<2)
                // continue;
                    int x1=f[j];
                    int y1=f[k];
                    if(pp[x1][y1]==1 || pp[y1][x1]==1)
                    {
                        
                    int cn1=adj[x1].size()-2+adj[y1].size()-2+adj[i].size()-2;
                    ans=min(ans,cn1);
                    }
                }
            }
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
        
    }
};