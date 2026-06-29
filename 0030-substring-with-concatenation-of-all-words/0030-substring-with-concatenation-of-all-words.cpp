class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int m = words.size();
        int k = words[0].size();

        vector<int> ans;
        if (n < m * k) return ans;

        unordered_map<string, int> need;
        for (auto &it : words)
            need[it]++;

        auto check = [&](unordered_map<string,int> &pp) {
            if (pp.size() != need.size()) return false;
            for (auto &it : need)
                if (pp[it.first] != it.second)
                    return false;
            return true;
        };

        for (int offset = 0; offset < k; offset++) {

            if (offset + m * k > n) break;

            unordered_map<string,int> pp;

            // Build first window
            for (int i = offset; i < offset + m * k; i += k)
                pp[s.substr(i, k)]++;

            if (check(pp))
                ans.push_back(offset);

            // Slide window
            for (int i = offset + m * k; i + k <= n; i += k) {

                string rem = s.substr(i - m * k, k);
                if (--pp[rem] == 0)
                    pp.erase(rem);

                pp[s.substr(i, k)]++;

                if (check(pp))
                    ans.push_back(i - (m - 1) * k);
            }
        }

        return ans;
    }
};