class Solution {
public:
vector<int>dr={-1,0,1};
int call(int lt,int i,int &n,vector<int>&st,unordered_map<int,int> &pp,vector<vector<int>>&dp)
{
    if(i>=n-1)
    {
        
        return 1;
    }
    if(dp[lt][i]!=-1)
    return dp[lt][i];
    for(auto it:dr)
    {
        int move=lt+it;
        if(move>=1 && pp.find(st[i]+move)!=pp.end())
        {
            if(call(move,pp[st[i]+move],n,st,pp,dp))
            return dp[lt][i]=1;
        }
    }
    return dp[lt][i]=0;
    
}
    bool canCross(vector<int>&st) 
    {
        
        unordered_map<int,int>pp;

        int n=st.size();
        if(st[1]-st[0]!=1)
        return 0;
        for(int i=0;i<n;i++)
        {
            pp[st[i]]=i;
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return call(1,1,n,st,pp,dp);
        
    }
};