typedef long long int ll;
#define F first
#define S second

class Solution {
    
    vector<vector<pair<int, char>>> g;
    unordered_map<int, int> frq;
    
    void dfs (int node, int path) {
        frq[path] ++;
        
        for (auto edge : g[node]) {
            int ch = edge.S - 'a';
            
            path ^= (1 << ch);
            dfs (edge.F, path);
            path ^= (1 << ch);
        }
    }
    
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        g.clear(), frq.clear();
        
        int nodes = parent.size();
        g.resize(nodes);
        for (int j = 1; j < nodes; j ++) {
            g[parent[j]].push_back({j, s[j]});
        }
        
        dfs (0, 0);
        
        ll result = 0;
        for (auto i : frq) {
            ll val = i.F, cnt = i.S;
                        
            for (int j = 0; j < 26; j ++) {
                ll other = val ^ (1 << j);
                
                if (frq.find(other) == frq.end()) continue;
                result += (cnt * frq[other]);
            }
            result += cnt*(cnt-1);
        }
        
        return result/2;
    }
};