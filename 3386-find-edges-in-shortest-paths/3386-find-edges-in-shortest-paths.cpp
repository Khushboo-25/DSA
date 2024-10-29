#define point pair<int,int>
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:edges)
        {
            int x=it[0],y=it[1],w=it[2];
            adj[x].push_back({y,w});
            adj[y].push_back({x,w});

        }
        int mn=INT_MAX;
        priority_queue<point,vector<point>,greater<point>>pq;
        pq.push({0,0});
        vector<int> vv(n,INT_MAX);
        // vector<int> parent(n,INT_MAX);
        // parent[0]=-1;
        vv[0]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            int d=it.first;
            int node=it.second;
            pq.pop();
            if(vv[node]<d)continue;
            for(auto next:adj[node])
            {
                int d2=next.second;
                int nw=next.first;
                if(d+d2<vv[nw])
                {
                    vv[nw]=d+d2;
                    // parent[nw]=node;
                    pq.push({vv[nw],nw});
                }
            }
        }
        // map<pair<int,int>,bool>pp;
        vector<bool> ans;
        for(auto it: edges)
        {
            ans.push_back(false);
        }
        if(vv[n-1]==INT_MAX)
       {
        // cout<<"*"; 
        return ans;
       }
        priority_queue<point,vector<point>,greater<point>>pq1;
        pq1.push({n-1,0});
        vector<int> vv2(n,INT_MAX);
        vv2[n-1]=0;
        while(!pq1.empty())
        {
            auto tp=pq1.top();
            int d=tp.second;
            int node=tp.first;
            pq1.pop();
            if(vv2[node]<d)continue;
            for(auto next:adj[node])
            {
                int d2=next.second;
                int nw=next.first;
                if(vv2[nw]>d+d2)
                {
                    vv2[nw]=d+d2;
                    pq1.push({nw,d+d2});
                }
            }
        }
        int i=0;
        for(auto it: edges)
        {
            int x=it[0];
            int y=it[1];
            int w=it[2];
            if((vv[x]!=INT_MAX && vv2[y]!=INT_MAX &&vv[x]+w+vv2[y]==vv[n-1]) || (vv2[x]!=INT_MAX && vv[y]!=INT_MAX &&vv2[x]+w+vv[y]==vv[n-1]))
            {
                ans[i]=true;
            }
            i++;
        }
        return ans;
    }
};