class Solution {
public:
int call(int i,int prev,int &n,string &s,unordered_map<string,int>&pp,vector<vector<int>>&dp)
{
    string cr=s.substr(prev-1+1,i-prev+1);
    // cout<<cr<<" ";
    
    if(i>=n)
    {
        if(pp[cr]==1)
        {
            cout<<cr<<" ";
            return 1;
        }
        return 0;
    }
    if(dp[i][prev]!=-1)
    return dp[i][prev];
    bool f=0;
    if(pp[cr]>0)
    {
        f|=call(i+1,i+1,n,s,pp,dp);
    }
    f|=call(i+1,prev,n,s,pp,dp);
    return dp[i][prev]=f;
    
}
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_map<string,int>pp;
        
        for(auto it:wordDict)
        {
            pp[it]=1;
            // cout<<it<<" *";
        }
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        return call(0,0,n,s,pp,dp);
    }
};