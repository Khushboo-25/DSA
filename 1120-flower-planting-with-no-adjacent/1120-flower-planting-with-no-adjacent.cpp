class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& ed) 
    {
        vector<vector<int>>adj(n);
        for(auto it:ed)
        {
            int x=it[0]-1;
            int y=it[1]-1;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        vector<int>vv(n,-1);
        for(int i=0;i<n;i++)
        {
            if(vv[i]==-1)
            {
                queue<int>pq;
                vv[i]=1;
                pq.push(i);
                while(!pq.empty())
                {
                    int node=pq.front();
                    pq.pop();
                    for(auto it:adj[node])
                    {
                        if(vv[it]==-1)
                        {
                            unordered_map<int,bool>pp;
                            for(auto it1:adj[it])
                            {
                                if(vv[it1]!=-1)
                                pp[vv[it1]]=1;
                            }
                            for(int k=1;k<=4;k++)
                            {
                                if(pp[k]!=1)
                                {
                                    vv[it]=k;
                                    pq.push(it);
                                    break;
                                }

                            }
                        }
                    }
                }
            }
        }
        return vv;

        
    }
};