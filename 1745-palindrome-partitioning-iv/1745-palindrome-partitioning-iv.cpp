class Solution {
public:
bool pr(int s,int e,string &st,vector<vector<int>>&dp)
{
    if(s>=e)
    return 1;
    if(dp[s][e]!=-1)
    return dp[s][e];
    if(st[s]!=st[e])
    return dp[s][e]=0;
    return dp[s][e]=pr(s+1,e-1,st,dp);
}
    bool checkPartitioning(string s)
    {
        int n=s.size();
        vector<bool>fr(n,0);
        string s2="";
        for(int i=0;i<n;i++)
        {
            s2=s[i]+s2;
            if(s.substr(0,i+1)==s2)
            fr[i]=1;
        }
        s2="";
        vector<int>br(n,0);
        for(int i=n-1;i>=0;i--)
        {
            s2+=s[i];
            if(s.substr(i)==s2)
            br[i]=1;
        }
        // for(auto it:fr)
        // cout<<it<<" ";
        // cout<<endl;
        // for(auto it:br)
        // {
        //     cout<<it<<" ";
        // }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+2;j<n;j++)
            {
                if(fr[i] && br[j] && pr(i+1,j-1,s,dp))
                return 1;
            }
        }
        return 0;


    }
};