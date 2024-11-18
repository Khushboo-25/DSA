class Solution {
public:
map<pair<int,int>,bool>dp;
bool call(int i,int prev,vector<int> &a,int &n)
{
    if(i==n-1)
    return 1;
    if(i>=n|| prev<=0)
    return 0;
    if(dp.find({i,prev})!=dp.end())
    return dp[{i,prev}];
    bool cn=0;
    for(int j=i;j<n;j++)
    {
        int d1=a[j]-a[i];
        if(d1==prev+1 || d1==prev-1 || d1==prev)
        cn|=call(j,d1,a,n);
        if(cn==1)
        return dp[{i,prev}]=1;

    }
    return dp[{i,prev}]=cn;
}
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        if(stones[1]-stones[0]!=1)
        return 0;
        return call(1,1,stones,n);
    }
};