class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        string start = "";
        for (auto &r : mat)
            for (int x : r)
                start += char('0' + x);

        if (start == string(n*m, '0')) return 0;

        vector<pair<int,int>> dr = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};

        queue<string> q;
        unordered_set<string> vis;

        q.push(start);
        vis.insert(start);

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string cur = q.front(); q.pop();
                if (cur == string(n*m, '0')) return steps;

                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {

                        string nxt = cur;
                        for (auto &d : dr) {
                            int x = i + d.first;
                            int y = j + d.second;
                            if (x>=0 && y>=0 && x<n && y<m) {
                                int idx = x*m + y;
                                nxt[idx] = (nxt[idx]=='0' ? '1' : '0');
                            }
                        }

                        if (!vis.count(nxt)) {
                            vis.insert(nxt);
                            q.push(nxt);
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
