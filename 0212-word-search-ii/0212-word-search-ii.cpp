class Solution {
public:
    int n, m;
    struct TrieNode {
        TrieNode* next[26] = {};
        string word = "";
    };

    void insert(TrieNode* root, const string &word) {
        for (char c : word) {
            if (!root->next[c - 'a']) 
                root->next[c - 'a'] = new TrieNode();
            root = root->next[c - 'a'];
        }
        root->word = word;
    }

    void dfs(int i, int j, vector<vector<char>> &brd, TrieNode* node, vector<string> &ans, unordered_set<int> &vis) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;

        int id = i * m + j;
        if (vis.count(id)) return;

        char c = brd[i][j];
        if (!node->next[c - 'a']) return;

        node = node->next[c - 'a'];
        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";  // avoid duplicates
        }

        vis.insert(id);

        dfs(i + 1, j, brd, node, ans, vis);
        dfs(i - 1, j, brd, node, ans, vis);
        dfs(i, j + 1, brd, node, ans, vis);
        dfs(i, j - 1, brd, node, ans, vis);

        vis.erase(id);
    }

    vector<string> findWords(vector<vector<char>>& brd, vector<string>& words) {
        n = brd.size();
        m = brd[0].size();

        TrieNode* root = new TrieNode();
        for (const string &word : words) {
            insert(root, word);
        }

        vector<string> ans;
        unordered_set<int> vis;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                dfs(i, j, brd, root, ans, vis);

        return ans;
    }
};
