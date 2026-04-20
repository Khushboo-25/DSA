class Solution {
public:
typedef pair<int,pair<int,int>> ppl;
vector<pair<int,int>>dr={{1,0},{-1,0},{0,-1},{0,1}};
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) 
    {
        vector<vector<int>>grid(n,vector<int>(m,0));
        vector<vector<int>>tm(n,vector<int>(m,INT_MAX));
        priority_queue<ppl,vector<ppl>,greater<ppl>>qt;
        for(auto it:sources)
        {
            // for(int j=0;j<m;j++)
            // {
                int x=it[0],y=it[1],c=it[2];
                grid[x][y]=c;
                // if(sources[i][j]!=0)
                // {
                    tm[x][y]=0;
                    qt.push({0,{x,y}});
            //     }
            // }
        }
        while(!qt.empty())
        {
            auto it=qt.top();
            int ti=it.first;
            int x=it.second.first;
            int y=it.second.second;
            qt.pop();
            for(auto it:dr)
            {
                int x1=x+it.first;
                int y1=y+it.second;
                if(x1>=0 && x1<n && y1>=0 && y1<m && tm[x1][y1]>=ti+1 && grid[x][y]>grid[x1][y1])
                {
                    grid[x1][y1]=grid[x][y];
                    tm[x1][y1]=ti+1;
                    qt.push({tm[x1][y1],{x1,y1}});
                }
            }
        }
        return grid;

    
        
    }
};