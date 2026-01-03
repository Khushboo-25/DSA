class Solution {
public:
int mod=1e9+7;
int call(int pv, int i, int &n, int S,
         map<pair<int,int>,bool>& pr,
         vector<vector<int>>& dp)
{
    if(i > n) return 1;
    if(dp[pv][i] != -1) return dp[pv][i];

    long long ans = 0;
    for(int j = 0; j < S; j++) {
        if(pr.find({pv, j}) == pr.end()) {
            ans = (ans + call(j, i+1, n, S, pr, dp)) % mod;
        }
    }
    return dp[pv][i] = ans;
}

void gen(int i, int m, vector<int>& cur, vector<vector<int>>& row) {
    if (i == m) {
        row.push_back(cur);
        return;
    }
    for (int c = 0; c < 3; c++) {
        if (i > 0 && cur[i-1] == c) continue;
        cur[i] = c;
        gen(i + 1, m, cur, row);
    }
}

    int colorTheGrid(int m, int n) {
        vector<vector<int>> row;
        vector<int> cur(m);
        gen(0, m, cur, row);
        int S = row.size();
        vector<vector<int>> dp (S, vector<int>(n+1, -1));

        map<pair<int,int>, bool> pr;

        for(int i = 0; i < S; i++) {
            for(int j = 0; j < S; j++) {
                bool bad = false;
                for(int c = 0; c < m; c++) {
                    if(row[i][c] == row[j][c]) {
                        bad = true;
                        break;
                    }
                }
                if(bad) pr[{i, j}] = 1;
            }
        }

        long long res = 0;
        for(int s = 0; s < S; s++) {
            res = (res + call(s, 2, n, S, pr, dp)) % mod;
        }
        return res;

    }
};