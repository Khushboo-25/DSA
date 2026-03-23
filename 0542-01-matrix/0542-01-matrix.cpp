class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int drow[]={0,1,0,-1};
        int dcol[]={-1,0,1,0};
        while(q.size())
        {
            int r=q.front().first;
            int c=q.front().second;
            // int t=q.front().second;
            // dis[r][c]=t;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&mat[nrow][ncol]==1 && dis[nrow][ncol]>dis[r][c]+1)
                {
                    dis[nrow][ncol]=dis[r][c]+1;
                    q.push({nrow,ncol});
                }
            }
        }
        return dis;
    }
};