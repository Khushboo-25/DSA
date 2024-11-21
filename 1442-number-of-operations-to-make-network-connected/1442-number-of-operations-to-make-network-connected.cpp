class Solution {
public:
void update(vector<int> &vv,int &mst,vector<vector<int>> &adj,int i)
  {
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      pq.push({0,i});
      while(!pq.empty())
      {
          auto it=pq.top();
          int d=it.first;
          int node=it.second;
          pq.pop();
          if(vv[node]==0)
          {
              vv[node]=1;
              mst+=d;
              for(auto it: adj[node])
              {
                  if(vv[it]==0)
                  {
                    //   vv[it]=d+1;
                      pq.push({1,it});
                  }
              }
          }
      }
  }
    int Solve(int n, vector<vector<int>>& edge) 
    {
        int med=edge.size();
        int cn=0;
        int mst=0;
        vector<int> vv(n,0);
        vector<vector<int> > adj(n);
        for(auto it:edge)
        {
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            if(vv[i]==0)
            {
                cn++;
                update(vv,mst,adj,i);
            }
        }
        if(med-mst>=cn-1)
        {
            return cn-1;
        }
        return -1;
        // code here
    }
    int makeConnected(int n, vector<vector<int>>& edge) 
    {
        int med=edge.size();
        int cn=0;
        int mst=0;
        vector<int> vv(n,0);
        vector<vector<int> > adj(n);
        for(auto it:edge)
        {
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            if(vv[i]==0)
            {
                cn++;
                update(vv,mst,adj,i);
            }
        }
        if(med-mst>=cn-1)
        {
            return cn-1;
        }
        return -1;
    }
};