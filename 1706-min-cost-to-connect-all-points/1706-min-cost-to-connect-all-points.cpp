#define   pll pair<int,int>
class Solution {
public:

int minsp(vector<vector<pair<int,int>>>&adj,int &n)
{
    int sm=0;
    priority_queue<pll,vector<pll>,greater<pll>>pq;
    pq.push({0,0});
    vector<int> vv(n,0);
    
    while(!pq.empty())
    {
        int nw=pq.top().second;
        int d1=pq.top().first;
        pq.pop();
        // sm+=d1;
        if(vv[nw]==0)
        {
            vv[nw]=1;
            sm+=d1;
            for(auto it: adj[nw])
            {

                int n1=it.first;
                int d2=it.second;
                if(vv[n1]==0)
                {
                    pq.push({d2,n1});
                }
            }
        }
        
    }
    return sm;

}
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int xi=points[i][0];
                int yi=points[i][1];
                int xj=points[j][0];
                int yj=points[j][1];
                int d=abs(xi-xj)+abs(yi-yj);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
        int sm=minsp(adj,n);
        return sm;
        
    }
};