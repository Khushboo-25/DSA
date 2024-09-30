class Solution {
public:
    int networkDelayTime(vector<vector<int>>& ad, int V, int S) {
        vector<vector<vector<int>>>adj(V+1);
        for(auto it: ad)
        {
            int x=it[0];
            int y=it[1];
            int d=it[2];
            adj[x].push_back({y,d});
        }
        vector<int> vv(V+1, INT_MAX); // Initialize distances to infinity
        vv[S] = 0; // Set distance of the source to 0 (1-based to 0-based index)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,S});
        while(!pq.empty())
        {
            auto it=pq.top();
            int d=it.first;
            int node=it.second;
            pq.pop();
            for(auto nw: adj[node])
            {
                int n1=nw[0];
                int d2=nw[1];
                if(d+d2<vv[n1])
                {
                    vv[n1]=d+d2;
                    pq.push({vv[n1],n1});
                }
            }

        }
        // Find the maximum distance
        int maxDist = 0;
        for (int i = 1 ;i <=V; ++i) {
            if (vv[i] == INT_MAX) { // If any node is unreachable, return -1
                return -1;
            }
            maxDist = max(maxDist, vv[i]);
        }
        
        return maxDist; // Maximum time it takes for all nodes to receive the signal
    }
};
