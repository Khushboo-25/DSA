class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        // int m=grid[0].size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        vector<vector<int>>vis(n,vector<int>(n,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        vis[0][0]=1;
        int delr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delc[8] = {-1,  0,  1, 1, 1, 0, -1, -1};
        // int ans=1;
        while(!q.empty()){
            // int size=q.size();
            
                int d=q.front().first;
                int row=q.front().second.first;
                int col=q.front().second.second;
                q.pop();
                // if(row==n-1 && col==m-1){
                //     return ans;
                // }
                for(int i=0;i<8;i++){
                    int nrow=row+delr[i];
                    int ncol=col+delc[i];

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n 
                    && grid[nrow][ncol]==0){
                        if(vis[nrow][ncol]>d+1)
                        {
                        q.push({d+1,{nrow,ncol}});
                        vis[nrow][ncol]=d+1;
                        }
                    }
                } 
            // ans++;
        }
        return vis[n-1][n-1]==INT_MAX?-1:vis[n-1][n-1];
    }
};