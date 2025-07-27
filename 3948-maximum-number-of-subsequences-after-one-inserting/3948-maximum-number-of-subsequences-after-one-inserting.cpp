class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<int> pl(n + 1, 0); // prefix count of 'L'
        vector<int> at(n + 1, 0); // suffix count of 'T'

        // Build prefix count of 'L'
        for (int i = 0; i < n; i++) {
            pl[i + 1] = pl[i] + (s[i] == 'L' ? 1 : 0);
        }

        // Build suffix count of 'T'
        for (int i = n - 1; i >= 0; i--) {
            at[i] = at[i + 1] + (s[i] == 'T' ? 1 : 0);
        }

        long long base = 0;   // No insert
        long long insL = 0;   // Insert 'L' before a C
        long long insT = 0;   // Insert 'T' after a C
        long long insC = 0;   // Insert 'C' between some L and T

        for (int i = 0; i < n; i++) {
            if (s[i] == 'C') {
                base += 1LL * pl[i + 1] * at[i];
                insL += at[i];        // 'L' inserted before
                insT += pl[i + 1];    // 'T' inserted after
            }
            // Try inserting 'C' between Ls and Ts
            insC = max(insC, 1LL * pl[i + 1] * at[i]);
        }

        // Return original + best improvement from one insert
        return base + max({insL, insT, insC});
    }
};
