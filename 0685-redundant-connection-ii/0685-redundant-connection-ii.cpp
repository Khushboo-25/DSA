class Solution {
public:
    bool call(int removeIdx, vector<vector<int>>& ed, int &n) {
        vector<int> in(n+1, 0);  // indegree (1-based)
        vector<vector<int>> adj(n+1);
        
        // Build graph without edge removeIdx
        for (int j = 0; j < n; j++) {
            if (j == removeIdx) continue;
            int u = ed[j][0], v = ed[j][1];
            in[v]++;
            adj[u].push_back(v);
        }

        // check indegree condition
        int root = -1;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                if (root != -1) return false; // more than one root
                root = i;
            } else if (in[i] > 1) {
                return false; // invalid indegree
            }
        }
        if (root == -1) return false; // no root

        // BFS/DFS to ensure connectivity and no cycle
        vector<int> vis(n+1, 0);
        int cnt = 0;
        queue<int> q;
        q.push(root);
        vis[root] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            cnt++;
            for (int v : adj[u]) {
                if (vis[v]) return false; // cycle detected
                vis[v] = 1;
                q.push(v);
            }
        }

        return cnt == n; // must visit all nodes
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& ed) {
        int n = ed.size();
        for (int i = n-1; i >= 0; i--) { 
            // try removing edges from last to first 
            if (call(i, ed, n)) {
                return ed[i];
            }
        }
        return {};
    }
};
