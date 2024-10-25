class Solution {
public:
vector<pair<int,int>>dr={{-1,0},{1,0},{0,1},{0,-1}};
void bfs(int n,int i,int j,vector<vector<int>> &vv,vector<vector<int>>&grid,int &m,unordered_map<int,int>&pp)
{
    vv[i][j]=1;
    pp[m]++;
    grid[i][j]=m;
    queue<pair<int,int>>pq;
    pq.push({i,j});
    while(!pq.empty())
    {
        auto it=pq.front();
        int x=it.first;
        int y=it.second;
        pq.pop();
        for(auto it:dr)
        {
            int i1=x+it.first;
            int j1=y+it.second;
            if(i1>=0 && i1<n && j1>=0 && j1<n && grid[i1][j1]==1 )
            {
                if(vv[i1][j1]==0)
                {
                    vv[i1][j1]=1;
                    grid[i1][j1]=m;
                    pp[m]++;
                    pq.push({i1,j1});
                }
            }
        }
    }
    
}
    int largestIsland(vector<vector<int>>& grid) 
    {
        
        int n=grid.size();
        unordered_map<int,int>pp; //mark,size
        
        int m=2;
        vector<vector<int>>vv(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    if(vv[i][j]==0)
                    {
                        bfs(n,i,j,vv,grid,m,pp);
                        m++;
                        // cn++;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    unordered_map<int,int>pp1;
                    int cn=1;
                    for(auto it:dr)
                    {
                        int x=i+it.first;
                        int y=j+it.second;
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]>1)
                        {
                            if(pp1[grid[x][y]]!=1)
                            {
                                cn+=pp[grid[x][y]];
                                pp1[grid[x][y]]=1;
                            }
                        }
                    }
                    ans=max(cn,ans);
                }
            }
        }
        for(auto it:pp)
        {
            ans=max(ans,it.second);
        }
        return ans;
        
    }
};