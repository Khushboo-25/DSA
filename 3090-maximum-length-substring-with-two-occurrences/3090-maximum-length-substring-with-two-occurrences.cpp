class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> cnt(26, 0);
        int l = 0, ans = 0;

        for (int r = 0; r < s.size(); r++) {
            cnt[s[r] - 'a']++;

            // shrink window if any character appears more than 2 times
            while (cnt[s[r] - 'a'] > 2) {
                cnt[s[l] - 'a']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
