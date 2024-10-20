#define point pair<int,pair<int,int>>
vector<pair<int,int>> dr={{-1,0},{1,0},{0,-1},{0,1}};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vv(n,vector<int>(m,INT_MAX));
        
        // if(!(grid[0][0]<=0))
        // return -1;
        priority_queue<point,vector<point>,greater<point>>pq;
        

        vv[0][0]=grid[0][0];
        pq.push({vv[0][0],{0,0}});
        while(!pq.empty())
        {
            auto it=pq.top();
            int tm=it.first;
            int x=it.second.first;
            int y=it.second.second;
            pq.pop();
            // bool check=0;
            for( auto it1: dr)
            {
                int x1=x+it1.first;
                int y1=y+it1.second;
                if(x1<n && x1>=0 && y1<m && y1>=0 )
                {
                    if(grid[x1][y1]<=tm)
                    {
                        if(vv[x1][y1]>tm)
                        {
                        vv[x1][y1]=tm;
                        pq.push({vv[x1][y1],{x1,y1}});
                        }
                        // // check=1;
                        // if(vv[x1][y1]>tm+1)
                        // {
                        //     vv[x1][y1]=tm+1;
                        //     pq.push({vv[x1][y1],{x1,y1}});
                        // }
                    }
                    else
                    {
                        if(vv[x1][y1]>grid[x1][y1])
                        {
                            vv[x1][y1]=grid[x1][y1];
                            pq.push({vv[x1][y1],{x1,y1}});
                        }
                        // vv[x1][y1]=min(grid[x1][y1],vv[x1][y1]);
                        // pq.push({vv[x1][y1],{x1,y1}});
                    }
                    
                }
            }
            // if(check)
            // {
            //     for( auto it: dr)
            //     {
            //         int x1=x+it.first;
            //         int y1=y+it.second;
            //         if(x1<n && x1>=0 && y1<m && y1>=0 )
            //         {
            //             if(grid[x1][y1]<=tm )
            //             {
            //                 int tm2=tm;
            //                 if(vv[x1][y1]>tm2)
            //                 {
            //                     vv[x1][y1]=tm2;
            //                     pq.push({vv[x1][y1],{x1,y1}});
            //                 }
            //             }
            //         }
            //     }
            // }
        }
        if(vv[n-1][m-1]==INT_MAX)
        return -1;
        return vv[n-1][m-1];
        
    }
};