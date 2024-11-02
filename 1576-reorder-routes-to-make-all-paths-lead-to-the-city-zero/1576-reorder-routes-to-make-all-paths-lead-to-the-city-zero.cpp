class Solution {
public:
    int minReorder(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, bool>>> adj(n);
        
        // Build the adjacency list
        for (auto& edge : edges) {
            adj[edge[0]].emplace_back(edge[1], true);  // Directed from edge[0] to edge[1]
            adj[edge[1]].emplace_back(edge[0], false); // Reverse direction from edge[1] to edge[0]
        }
        
        return dfs(0, -1, adj);
    }

private:
    int dfs(int node, int parent, vector<vector<pair<int, bool>>>& adj) {
        int count = 0;

        for (auto& [neighbor, dir] : adj[node]) {
            if (neighbor != parent) {
                if (dir) {
                    count++;  // Count the edge if it is directed away from the node
                }
                count += dfs(neighbor, node, adj);
            }
        }

        return count;
    }
};