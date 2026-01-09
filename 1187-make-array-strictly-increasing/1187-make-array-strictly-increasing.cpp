class Solution {
public:
    const int INF = 1e9;
    map<pair<int,int>, int> dp;

    int solve(int i, int prev, vector<int>& a, vector<int>& b) {
        if (i == a.size()) return 0;

        if (dp.count({i, prev})) return dp[{i, prev}];

        int ans = INF;

        // Option 1: keep a[i]
        if (a[i] > prev) {
            ans = solve(i + 1, a[i], a, b);
        }

        // Option 2: replace with smallest b[j] > prev
        auto it = upper_bound(b.begin(), b.end(), prev);
        if (it != b.end()) {
            ans = min(ans, 1 + solve(i + 1, *it, a, b));
        }

        return dp[{i, prev}] = ans;
    }

    int makeArrayIncreasing(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        int res = solve(0, -1e9, a, b);
        return res >= INF ? -1 : res;
    }
};
