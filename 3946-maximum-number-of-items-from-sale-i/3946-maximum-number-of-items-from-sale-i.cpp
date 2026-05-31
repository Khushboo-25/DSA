class Solution {
public:
int call(int cr,int i,int bd,int &n,unordered_map<int,int>&cp,unordered_map<int,int>&pr,vector<vector<vector<int>>>&dp)
{
    if(i>=n )
    return 0;
    if(dp[cr][i][bd]!=-1)
    return dp[cr][i][bd];
    int ans=0;
    if(bd>=pr[i])
    {
        if(cr==0)
        ans=max(ans,1+cp[i]+call(1,i,bd-pr[i],n,cp,pr,dp));
        else
        ans=max(ans,1+call(1,i,bd-pr[i],n,cp,pr,dp));
    }
    ans=max(ans,call(0,i+1,bd,n,cp,pr,dp));
    return dp[cr][i][bd]=ans;
}
    int maximumSaleItems(vector<vector<int>>& item, int bd) 
    {
        int n=item.size();
        unordered_map<int,int>pr;
        unordered_map<int,int>cp;
        for(int i=0;i<n;i++)
        {
            pr[i]=item[i][1];
            int fi=item[i][0];
            for(int j=0;j<n;j++)
            {
                int fj=item[j][0];
                if(i!=j && fj%fi==0)
                {
                    cp[i]++;
                }
            }
        }
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(bd+1,-1)));
        int ans=call(0,0,bd,n,cp,pr,dp);
        return ans;
        
    }
};