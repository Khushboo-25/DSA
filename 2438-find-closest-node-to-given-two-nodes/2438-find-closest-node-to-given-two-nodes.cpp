class Solution {
public:
void call(int &i,vector<int>&d,vector<vector<int>>&adj)
{
    d[i]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({d[i],i});
    while(!pq.empty())
    {
        int ds=pq.top().first;
        int x=pq.top().second;
        pq.pop();
        for(auto it:adj[x])
        {
            if(d[it]>1+ds)
            {
                d[it]=1+ds;
                pq.push({d[it],it});
            }
        }
    }
}
    int closestMeetingNode(vector<int>& ed, int node1, int node2) 
    {
        int n=ed.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            if(ed[i]!=-1)
            adj[i].push_back(ed[i]);
        }
        vector<int>d1(n,n+1),d2(n,n+1);
        
        call(node1,d1,adj);
        call(node2,d2,adj);
        long long ans=2*1ll*(n+1);
        for(int i=0;i<n;i++)
        {
            long long ans1=max(d1[i],d2[i]);
            if(ans1!=(n+1)*1ll)
            ans=min(ans1,ans);
        }
        if(ans==(n+1)*2*1ll)
            return -1;
        for(int i=0;i<n;i++)
        {
            long long ans1=max(d1[i],d2[i]);
            if(ans1==ans)
            return i;
        }
        return -1;
        
    }
};