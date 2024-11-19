class Solution {
public:
map<pair<int,int>,bool>pp;
map<pair<int,int>,bool>pp1;
#define  pl pair<int,pair<int,int>>
void call(vector<vector<int>> &vv,vector<vector<int>>adj,int &n)
{
    vv[0][0]=0;
    vv[0][1]=0;
    priority_queue<pl,vector<pl>,greater<pl>>pq;
    pq.push({0,{1,0}});
    pq.push({0,{0,0}});
    while(!pq.empty())
    {
        int nw=pq.top().second.second;
        int rq=pq.top().second.first;
        int d=pq.top().first;
        pq.pop();
        for(auto it:adj[nw])
        {
            int n1=it;
            if(rq==1 && pp.find({nw,n1})!=pp.end() && pp[{nw,n1}]==1)
            {
                if(vv[n1][1]>1+d)
                {
                    vv[n1][1]=1+d;
                    pq.push({1+d,{0,n1}});
                }
            }
            if(rq==0 && pp1.find({nw,n1})!=pp.end() && pp1[{nw,n1}]==1)
            {
                 if(vv[n1][0]>1+d)
                {
                    vv[n1][0]=1+d;
                    pq.push({1+d,{1,n1}});
                }
            }
        }
    }

}
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& rd, vector<vector<int>>& bd) 
    {
        vector<vector<int>>adj(n);
        for(auto it:rd)
        {
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            // adj[y].push_back(x);
            pp[{x,y}]=1;
            // pp[{y,x}]=1;
        }
        for(auto it:bd)
        {
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            // adj[y].push_back(x);
            pp1[{x,y}]=1;
            // pp[{y,x}]=-1;
        }
        vector<vector<int>> vv(n,vector<int>(2,INT_MAX));
        call(vv,adj,n);
        vector<int> ans;
        for(auto &it: vv)
        {
            int d=min(it[0],it[1]);
            if(d==INT_MAX)
            ans.push_back(-1);
            else
            ans.push_back(d);
        }
        return ans;
    }
};