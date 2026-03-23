class Solution {
public:
void call(int i,vector<vector<int>>&adj,vector<int>&vv)
{
    vv[i]=1;
    for(auto it:adj[i])
    {
        if(vv[it]==0)
        call(it,adj,vv);
    }
}
    int findCircleNum(vector<vector<int>>& ed) 
    {
        int n=ed.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(ed[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int>vv(n,0);
        for(int i=0;i<n;i++)
        {
            if(vv[i]==0)
            {
                ans++;
                call(i,adj,vv);
            }
        }
        return ans;
        
    }
};