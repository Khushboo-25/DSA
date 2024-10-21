#define point pair<int,pair<int,int>>
vector<pair<int,int>>dr={{-1,0},{1,0},{0,1},{0,-1}};
class Solution {
public:
int call(int i,int j,vector<vector<int>>& mat,int &n,int &m,vector<vector<int>>&vv)
{
    // vector<vector<int>>vv(n,vector<int>(m,0));
    // return call2(i,j,n,m,vv,mat);
    int ans=0;
    
    priority_queue<point>pq;
    pq.push({1,{i,j}});
    vv[i][j]=1;
    while(!pq.empty())
    {
        auto it=pq.top();
        int d=it.first;
        int x=it.second.first;
        int y=it.second.second;
        pq.pop();
        
        for(auto it1:dr)
        {
            int x1=x+it1.first;
            int y1=y+it1.second;
            if(x1<n && x1>=0 && y1>=0 && y1<m && mat[x1][y1]>mat[x][y])
            {
                if(vv[x1][y1]<d+1)
                {
                    vv[x1][y1]=d+1;
                    pq.push({vv[x1][y1],{x1,y1}});
                }
            }

        }
       
    }
     for(int k=0;k<n;k++)
        {
            for(int l=0;l<m;l++)
            {
                ans=max(ans,vv[k][l]);
            }
        }
        
    return ans;


}
    int longestIncreasingPath(vector<vector<int>>& mat) 
    {
        int ans=0;
        int n=mat.size(),m=mat[0].size();
        
                vector<vector<int>>vv(n,vector<int>(m,-1));
                
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vv[i][j]==-1)
                ans=max(ans,call(i,j,mat,n,m,vv));
                // cout<<"*****"<<endl;
                // for(int i=0;i<n;i++)
                // {
                //     for(int j=0;j<m;j++)
                //     {
                //         cout<<vv[i][j]<< " ";

                //     }
                //     cout<<endl;
                // }

               
                
            }
        }
        return ans;
    }
};