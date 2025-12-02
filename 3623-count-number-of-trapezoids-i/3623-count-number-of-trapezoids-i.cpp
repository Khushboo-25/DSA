class Solution {
public:
    int mod = 1e9 + 7;

    long long comb2(long long n) {
        return n * (n - 1) / 2;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> y_map;
        for (auto& p : points) {
            y_map[p[1]]++;
        }

        vector<long long> combs;
        for (auto& it : y_map) {
            if (it.second >= 2)
                combs.push_back(comb2(it.second));
        }

        long long total_sum = 0;
        long long square_sum = 0;

        for (long long val : combs) {
            total_sum = (total_sum + val) % mod;
            square_sum = (square_sum + (val * val) % mod) % mod;
        }

        long long res = ((total_sum * total_sum) % mod - square_sum + mod) % mod;
        res = (res * ((mod + 1) / 2)) % mod; // Multiply by inverse of 2 mod 1e9+7

        return res;
    }
};
