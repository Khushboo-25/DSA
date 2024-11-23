class Solution {
public:
bool call(int s,int e,string &st,int &n,vector<vector<int> > &dp1)
{
    if(s>e)
    return 1;
    if(dp1[s][e]!=-1)
    return dp1[s][e];
    if(st[s]==st[e])
    {
        return dp1[s][e]=call(s+1,e-1,st,n,dp1);
    }
    else
    return dp1[s][e]=0;
}
    int minCut(string s) 
    {
        int n=s.size();
        vector<int> dp(n+1,INT_MAX);
        vector<vector<int> > dp1(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                call(i,j,s,n,dp1);
            }
        }
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            int ans1=INT_MAX;
            for(int j=i;j<n;j++)
            {
                if(dp1[i][j]==1)
                {
                    ans1=min(ans1,1+dp[j+1]);
                }
            }
            dp[i]=ans1;
        }
        return dp[0]-1;

        
    }
};