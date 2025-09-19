class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "-1";
        }
        string ans = to_string(root->val);
        ans += "(" + serialize(root->left) + ")";
        ans += "(" + serialize(root->right) + ")";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return buildTree(data, idx);
    }

private:
    TreeNode* buildTree(const string &s, int &i) {
        if (i >= s.size()) return NULL;

        // Handle "-1"
        if (s[i] == '-' && s[i+1] == '1') {
            i += 2; // skip "-1"
            return NULL;
        }

        // Parse integer value
        int num = 0;
        
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            i++;
        }
        
        TreeNode* node = new TreeNode(num);

        // Parse left subtree
        if (i < s.size() && s[i] == '(') {
            i++; // skip '('
            node->left = buildTree(s, i);
            i++; // skip ')'
        }

        // Parse right subtree
        if (i < s.size() && s[i] == '(') {
            i++;
            node->right = buildTree(s, i);
            i++;
        }

        return node;
    }
};
