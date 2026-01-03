class Solution {
public:
int mod=1e9+7;
int call(int pv,int i,int &n,map<pair<int,int>,bool>&pr,vector<vector<int>>&dp)
{
    if(i>n)
    return 1;
    int ans=0;
    if(dp[pv][i]!=-1)
    return dp[pv][i];
    for(int j=1;j<=12;j++)
    {
        if(pr.find({pv,j})==pr.end())
        {
            ans=(ans+(call(j,i+1,n,pr,dp))%mod)%mod;
        }
    }
    return dp[pv][i]=ans;
}
    int numOfWays(int n) 
    {
        vector<vector<int>> row = {
            {},                 // dummy (1-based index)
            {0,1,0}, {0,2,0}, {1,0,1}, {1,2,1}, {2,0,2}, {2,1,2},
            {0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}
        };
        vector<vector<int>>dp(13,vector<int>(n+1,-1));
        map<pair<int,int>, bool> pr;

        // mark INVALID adjacents
        for(int i = 1; i <= 12; i++) {
            for(int j = 1; j <= 12; j++) {
                bool bad = false;
                for(int c = 0; c < 3; c++) {
                    if(row[i][c] == row[j][c]) {
                        bad = true;
                        break;
                    }
                }
                if(bad) pr[{i, j}] = 1;
            }
        }
        return call(0,1,n,pr,dp);
    }
};