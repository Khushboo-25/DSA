class Solution {
public:
int call(int i,int m0,int m1,int &n,int &n0,int &n1,vector<pair<int,int>>&st,vector<vector<vector<int>>>&dp)
{
    if(i>=n)
    return 0;
    int ans=0;
    if(dp[i][m0][m1]!=-1)
    return dp[i][m0][m1];
    ans=max(ans,call(i+1,m0,m1,n,n0,n1,st,dp));
    if((m0+st[i].first)<=n0 && (m1+st[i].second)<=n1)
    {
        ans=max(ans,1+call(i+1,m0+st[i].first,m1+st[i].second,n,n0,n1,st,dp));
    }
    return dp[i][m0][m1]=ans;
}
    int findMaxForm(vector<string>& str, int &n0, int &n1) 
    {
        int n=str.size();
        vector<pair<int,int>>st;
        for(auto it: str)
        {
            int m0=0;
            int m1=0;
            for(auto it1:it)
            {
                if(it1=='0')
                m0++;
                else
                m1++;
            }
            st.push_back({m0,m1});
        }
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n0+1,vector<int>(n1+1,-1)));
        return call(0,0,0,n,n0,n1,st,dp);
    }
};