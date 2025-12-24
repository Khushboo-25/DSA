class Solution {
public:
    long long minCost(string s, vector<int>& cost) 
    {
        int n=s.size();
        vector<vector<long long>>ans(n+1,vector<long long>(26,LLONG_MAX));
        for(int i=0;i<26;i++)
        ans[0][i]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(char c='a';c<='z';c++)
            {
                if(s[i-1]==c)
                {
                    ans[i][c-'a']=ans[i-1][c-'a'];
                }
                else
                ans[i][c-'a']=ans[i-1][c-'a']+cost[i-1];
            }
        }
        long long ans1=LLONG_MAX;
        for(int i=0;i<26;i++)
        {
            ans1=min(ans1,ans[n][i]);
        }
        return ans1;
    }
};