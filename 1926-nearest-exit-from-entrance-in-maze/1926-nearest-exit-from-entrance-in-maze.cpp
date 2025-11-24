class Solution {
public:
vector<pair<int,int>>dr={{-1,0},{1,0},{0,1},{0,-1}};
void  call(vector<vector<int>>&dis,vector<vector<char>>&maze,int &n,int &m,int &sx,int &sy)
{
    dis[sx][sy]=0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{sx,sy}});
    while(!pq.empty())
    {
        int d=pq.top().first;
        int x1=pq.top().second.first;
        int y1=pq.top().second.second;
        pq.pop();
        for(auto it: dr)
        {
            int nx=x1+it.first;
            int ny=y1+it.second;
            if(nx>=0 && nx<n && ny>=0 && ny<m)
            {
                if(maze[nx][ny]=='.' && dis[nx][ny]>1+d)
                {
                    dis[nx][ny]=1+d;
                    pq.push({1+d,{nx,ny}});
                }
            }
        }
    }
}
    int nearestExit(vector<vector<char>>& maze, vector<int>& et) 
    {
        int n=maze.size();
        int m=maze[0].size();
        int ans=INT_MAX;
        int sx=et[0],sy=et[1];
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        call(dis,maze,n,m,sx,sy);
        for(int i=0;i<n;i++)
        {
            if(!(sx==i && sy==0))
            {
                ans=min(ans,dis[i][0]);
            }
            if(!(sx==i && sy==m-1))
            {
                ans=min(ans,dis[i][m-1]);
            }
        }
        for(int i=1;i<m-1;i++)
        {
            
            if(!(sx==0 && sy==i))
            {
                ans=min(ans,dis[0][i]);
            }
            if(!(sx==n-1 && sy==i))
            {
                ans=min(ans,dis[n-1][i]);
            }
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
        
    }
};