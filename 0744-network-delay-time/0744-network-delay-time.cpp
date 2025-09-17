class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it: times)
        {
            int x=it[0];
            int y=it[1];
            int w=it[2];
            adj[x].push_back({y,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pp;
        vector<int>vv(n+1,INT_MAX);
        vv[k]=0;
        pp.push({0,k});
        while(!pp.empty())
        {
            auto tp=pp.top();
            pp.pop();
            int w1=tp.first;
            int x1=tp.second;
            for(auto it:adj[x1])
            {
                int x2=it.first;
                int d2=it.second;
                if(d2+w1<vv[x2])
                {
                    vv[x2]=w1+d2;
                    pp.push({vv[x2],x2});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,vv[i]);
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
    }
};