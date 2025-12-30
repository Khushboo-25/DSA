class Solution {
public:
    void update(int i, int e1, int e, string &st, long long &ans)
    {
        string ss = "";
        int s1 = i, s2 = e1 + 1;

        while (s1 <= e1 && s2 <= e)
        {
            if (st[s1] <= st[s2])
            {
                ss += st[s1];
                s1++;
            }
            else
            {
                // inversion found: '1' before '0'
                ans += (e1 - s1 + 1);
                ss += st[s2];
                s2++;
            }
        }

        while (s1 <= e1)
        {
            ss += st[s1];
            s1++;
        }

        while (s2 <= e)
        {
            ss += st[s2];
            s2++;
        }

        // copy back to original string
        for (int k = 0; k < ss.size(); k++)
        {
            st[i + k] = ss[k];
        }
    }

    void call(int s, int e, string &st, long long &ans)
    {
        if (s >= e)
            return;

        int m = s + (e - s) / 2;
        call(s, m, st, ans);
        call(m + 1, e, st, ans);
        update(s, m, e, st, ans);
    }

    long long minimumSteps(string s)
    {
        long long ans = 0;
        call(0, s.size() - 1, s, ans);
        return ans;
    }
};
