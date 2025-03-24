class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<long long>> comb;

    void precompute(int n) {
        comb.resize(n + 1, vector<long long>(n + 1, 1));
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
            }
        }
    }

    int count(vector<int>& nums) {
        if (nums.size() <= 2) return 1;
        vector<int> lf, rf;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[0]) lf.push_back(nums[i]);
            else rf.push_back(nums[i]);
        }
        long long lc = count(lf);
        long long rc = count(rf);
        long long tc = comb[lf.size() + rf.size()][rf.size()];
        return ((lc % mod) * (rc % mod) % mod * (tc % mod)) % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        precompute(n);  // Precompute binomial coefficients
        return (count(nums) - 1 + mod) % mod;
    }
};
