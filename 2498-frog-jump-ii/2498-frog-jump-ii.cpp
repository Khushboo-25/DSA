class Solution {
public:
    bool call(int m, int &n, vector<int>& st)
    {
        vector<int> vis(n, 0);

        // forward
        int i = 0;
        vis[0] = 1;

        while (i < n - 1)
        {
            int j = i;
            // go as far as possible within m
            while (j + 1 < n && st[j + 1] - st[i] <= m)
                j++;

            if (j == i) return false; // can't move

            vis[j] = 1;
            i = j;
        }

        // backward (cover remaining stones)
        int last = n - 1;
        for (int k = n - 1; k >= 0; k--)
        {
            if (!vis[k])
            {
                if (st[last] - st[k] > m)
                    return false;
                last = k;
            }
        }
        if(st[last]-st[0]>m)
        return 0;
        return true;
    }

    int maxJump(vector<int>& st) 
    {
        int n = st.size();
        int s = 1, e = st.back();
        int ans = e;

        while (s <= e)
        {
            int m = s + (e - s) / 2;

            if (call(m, n, st))
            {
                ans = m;
                e = m - 1;
            }
            else
                s = m + 1;
        }

        return ans;
    }
};