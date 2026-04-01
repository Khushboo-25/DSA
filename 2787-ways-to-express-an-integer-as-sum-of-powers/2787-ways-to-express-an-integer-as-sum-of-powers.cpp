class Solution {
public:
    int mod = 1e9+7;

    int call(int r, int i, int m, vector<int>& pw, vector<vector<int>>& dp)
    {
        if(r == 0) return 1;
        if(r < 0 || i >= m) return 0;

        if(dp[r][i] != -1) return dp[r][i];

        int take = call(r - pw[i], i + 1, m, pw, dp);
        int skip = call(r, i + 1, m, pw, dp);

        return dp[r][i] = (take + skip) % mod;
    }

    int numberOfWays(int n, int x) 
    {
        vector<int> pw;

        for(int i = 1;i<=n ; i++)
        {
            long long val = 1;
            for(int j = 0; j < x; j++) val *= i;

            if(val > n) break;
            pw.push_back(val);
        }

        int m = pw.size();
        vector<vector<int>> dp(n+1, vector<int>(m, -1));

        return call(n, 0, m, pw, dp);
    }
};