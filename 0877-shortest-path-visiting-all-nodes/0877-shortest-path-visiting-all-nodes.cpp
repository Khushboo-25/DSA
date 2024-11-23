class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<vector<bool>>vv(n,vector<bool> (1<<n,false));
        queue<pair<int,int>>pq;
        // node visit_hash
        for(int i=0;i<n;i++)
        {
            pq.push({i,1<<i});
            vv[i][1<<i]=1;
        }
        int st=0;
        while(!pq.empty())
        {
            int sz=pq.size();
            for(int i=0;i<sz;i++)
            {
                int node=pq.front().first;
                int vhash=pq.front().second;
                pq.pop();
                if(vhash==(1<<n)-1)
                return st;
                for(auto it:graph[node])
                {
                    int nwhash=vhash|(1<<it);
                    if(vv[it][nwhash]==false)
                    {
                        vv[it][nwhash]=1;
                        pq.push({it,nwhash});
                    }
                }
            }
            st++;

        }
        return st;
    }
};