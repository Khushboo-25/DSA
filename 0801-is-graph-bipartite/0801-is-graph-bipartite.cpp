class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vv(n,0);
        for(int i=0;i<n;i++)
        {
            if(vv[i]==0)
            {
            queue<pair<int,int>>pq;
            pq.push({i,1});
            vv[i]=1;
            while(!pq.empty())
            {
                int node=pq.front().first;
                int col=pq.front().second;
                pq.pop();
                for(auto it: graph[node])
                {
                    if(vv[it]>0)
                    {
                        if(vv[it]==col)
                        return 0;
                    }
                    else
                    {
                        if(col==1)
                        vv[it]=2;
                        else
                        vv[it]=1;
                        pq.push({it,vv[it]});
                    }
                }
            }
            }
        }
        return 1;
    }
};