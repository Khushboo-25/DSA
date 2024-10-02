class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& ed, vector<double>& sc, int st, int et) {
        vector<vector<pair<int,double>>> adj(n);
        int m=ed.size();
        for(int i=0;i<m;i++)
        {
            int x=ed[i][0];
            int y=ed[i][1];
            adj[x].push_back({y,sc[i]});
            adj[y].push_back({x,sc[i]});
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,st});
        vector<double> vv(n,0.0);
        vv[st]=1.0;
        while(!pq.empty())
        {
            auto it=pq.top();
            double d=it.first;
            int node=it.second;
            pq.pop();
            for(auto it1: adj[node])
            {
                int n1=it1.first;
                double d2=it1.second;
                if(vv[n1]<d*d2*1.0)
                {
                    vv[n1]=d*d2*1.0;
                    
                    pq.push({d*d2*1.0,n1});
                }

            }
        }
        return vv[et];
        

    }
};