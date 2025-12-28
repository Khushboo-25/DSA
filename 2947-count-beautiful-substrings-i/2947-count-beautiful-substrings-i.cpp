class Solution {
public:

    int beautifulSubstrings(string s, int k) 
    {
        unordered_map<char,bool>pp;
        int n=s.size();
        pp['a']=1,pp['e']=1,pp['i']=1,pp['o']=1,pp['u']=1;
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];

            if(pp.find(s[i-1])!=pp.end())
            {
                dp[i][0]++;
            }
            else
            dp[i][1]++;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int vl=dp[j+1][0]-dp[i][0];
                int cl=dp[j+1][1]-dp[i][1];
                long long m1=vl*cl;
                if(vl==cl && (m1)%k==0)
                ans++;
            }
        }
        return ans;
    }
};