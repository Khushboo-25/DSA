class Solution {
public:
void call(int i,vector<vector<int>>&adj,vector<int>&vv)
{
    vv[i]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({vv[i],i});
    while(!pq.empty())
    {
        int d=pq.top().first;
        int x=pq.top().second;
        pq.pop();
        for(auto it:adj[x])
        {
            if(vv[it]>1+d)
            {
                vv[it]=1+d;
                pq.push({vv[it],it});
            }
        }
    }
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& qr) 
    {
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++)
        {
            adj[i-1].push_back(i);
        }
        int nq=qr.size();
        vector<int>ans;
        
        for(int i=0;i<nq;i++)
        {
            int x=qr[i][0];
            int y=qr[i][1];
            adj[x].push_back(y);
            vector<int>vv(n,INT_MAX);
            call(0,adj,vv);
            ans.push_back(vv[n-1]);
        }
        return ans;
        
    }
};