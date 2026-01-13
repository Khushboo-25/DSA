class Solution {
public:
    vector<int> zfunc(string s)
    {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            if (i <= r)
                z[i] = min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }

    int minStartingIndex(string s, string p)
    {
        int n = s.size(), m = p.size();

        string a = p + "#" + s;
        auto z1 = zfunc(a);

        string rs = s, rp = p;
        reverse(rs.begin(), rs.end());
        reverse(rp.begin(), rp.end());

        string b = rp + "#" + rs;
        auto z2 = zfunc(b);

        for (int i = 0; i + m - 1 < n; i++)
        {
            int pref = z1[m + 1 + i];
            int suf = z2[m + 1 + (n - 1 - (i + m - 1))];

            if (pref == m) return i;
            if (pref + suf >= m - 1) return i;
        }
        return -1;
    }
};
