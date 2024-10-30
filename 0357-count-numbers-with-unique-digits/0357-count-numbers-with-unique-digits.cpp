class Solution {
public:
int call(int p,int d)
{

    int mup=1;
    // if(p==0)
    // return mup;
    while(p--)
    {
        mup*=d;
        d--;
    }
    return mup;
}
    int countNumbersWithUniqueDigits(int n) 
    {
        // if(n==0)
        // return ;
        unordered_map<int,int>dp;
        dp[0]=1;
        // dp[1]=10;
        
        for(int i=1;i<=n;i++)
        {
           dp[i]=dp[i-1]+9*call(i-1,9);
        }
        return dp[n];
    }
};