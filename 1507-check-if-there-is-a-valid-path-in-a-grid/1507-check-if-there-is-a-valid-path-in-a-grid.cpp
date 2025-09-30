class Solution {
public:
bool path(int x1,int y1,int t1,int x2,int y2,int t2)
{
    if(x2==x1+1 && y2==y1)// 2 is bottom
    {
        if((t1==2 || t1==3 || t1==4) && (t2==5 || t2==6 || t2==2))
        return 1;
    }
    else if(x2==x1-1 && y2==y1) //2 is on top
    {
        if((t1==5 || t1==4 || t1==2) && (t2==2 || t2==3 || t2==4))
        return 1;
    }
    else if(x2==x1 && y2==y1+1) // 2 is right
    {
        if((t1==1 || t1==4 || t1==6) && (t2==1 || t2==3 || t2==5))
        return 1;
    }
    else if(x2==x1 && y2==y1-1) // 2 is left
    {
        if((t1==1 || t1==3 || t1==5) && (t2==1 || t2==4 || t2==6))
        return 1;
    }
    return 0;
}
vector<pair<int,int>>dr={{0,1},{1,0},{0,-1},{-1,0}};
void call(int i,int j,int &n,int &m,vector<vector<int>>&grid,vector<vector<int>>&vv,vector<vector<bool>>&ps)
{
    vv[i][j]=1;
    ps[i][j]=1;
    int t1=grid[i][j];
    for(auto it: dr)
    {
        int i1=i+it.first;
        int j1=j+it.second;
        if(i1<n && j1<m && i1>=0 && j1>=0 && vv[i1][j1]==0 && path(i,j,t1,i1,j1,grid[i1][j1]))
        {
            call(i1,j1,n,m,grid,vv,ps);
        }
    }
}
    bool hasValidPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vv(n,vector<int>(m,0));
        vector<vector<bool>>ps(n,vector<bool>(m,0));
        call(0,0,n,m,grid,vv,ps);
        return vv[n-1][m-1];
        
    }
};