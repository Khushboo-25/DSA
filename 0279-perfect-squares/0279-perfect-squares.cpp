class Solution {
public:
int call(int i,int n,vector<int>&vv,int sum,vector<vector<int>>&dp)
{
    if(i>=n)
    {
        if(sum!=0)
        return 1e5;
        else
        return 0;
    }
    if(dp[i][sum]!=-1)
    return dp[i][sum];
    int cn=0;
    int n1=1e5,n2=1e5,n3=1e5;
    if(sum>=vv[i])
    {
        n1=1+call(i+1,n,vv,sum-vv[i],dp);
        n3=1+call(i,n,vv,sum-vv[i],dp);
    }
    n2=call(i+1,n,vv,sum,dp);
    
    cn=min(n1,min(n2,n3));
    // if()
    return dp[i][sum]=cn;

}
    int numSquares(int sum) 
    {
        vector<int> vv;
        
        for(int i=1;i*i<=sum;i++)
        {
            vv.push_back(i*i);
        }
        int n1=vv.size();
        vector<vector<int>>dp(n1+1,vector<int>(sum+1,-1));
        int ans= call(0,n1,vv,sum,dp);
        return ans==-1?-1:ans;

        
    }
};