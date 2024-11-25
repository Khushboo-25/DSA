#define pl pair<int,pair<int,int>>
class Solution {
public:
vector<vector<int>>dr={{0,1},{0,-1},{-1,0},{1,0}};
vector<vector<int>>dr2={{0,-2},{1,-1},{2,0},{1,1},{0,2},{-1,1},{-2,0},{-1,-1}};

    int minTimeToReach(vector<vector<int>>& mat) 
    {
        int n=mat.size(),m=mat[0].size();
       vector<vector<int>>vv(n,vector<int>(m,INT_MAX));
       priority_queue<pl,vector<pl>,greater<pl>>pq;
       pq.push({0,{0,0}});
       vv[0][0]=0;
       while(!pq.empty())
       {
            auto it=pq.top();
            int d=it.first;
            int x=it.second.first;
            int y=it.second.second;
            pq.pop();
             if (d > vv[x][y]) continue;
            for(auto dr1:dr)
            {
                int x1=x+dr1[0];
                int y1=y+dr1[1];
                if(x1<n && x1>=0 && y1<m && y1>=0)
                {
                    if(d>=mat[x1][y1])
                    {
                        if(vv[x1][y1]>1+d)
                        {
                            vv[x1][y1]=1+d;
                            pq.push({vv[x1][y1],{x1,y1}});
                        }
                    }
                    else
                    {
                        vv[x1][y1]=1+mat[x1][y1];
                        pq.push({vv[x1][y1],{x1,y1}});
                    }
                }
            }
             for(auto dr1:dr2)
            {
                int x1=x+dr1[0];
                int y1=y+dr1[1];
                if(x1<n && x1>=0 && y1<m && y1>=0)
                {
                    if(d>=mat[x1][y1])
                    {
                        if(vv[x1][y1]>2+d)
                        {
                            vv[x1][y1]=2+d;
                            pq.push({vv[x1][y1],{x1,y1}});
                        }
                    }
                    else
                    {
                        vv[x1][y1]=2+mat[x1][y1];
                        pq.push({vv[x1][y1],{x1,y1}});
                    }
                }
            }
       }
       return vv[n-1][m-1];


    }
};