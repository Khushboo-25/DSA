/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

void gen(int n, vector<int> &curr, vector<bool> &used, vector<vector<int>> &ans) {
    if (curr.size() == n) {
        ans.push_back(curr);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            curr.push_back(i);
            gen(n, curr, used, ans);
            curr.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> genP(int n) {
    vector<vector<int>> ans;
    vector<int> curr;
    vector<bool> used(n + 1, false);
    gen(n, curr, used, ans);
    return ans;
}

void insert(TreeNode* root, int val) {
    while (true) {
        if (val < root->val) {
            if (!root->left) {
                root->left = new TreeNode(val);
                return;
            }
            root = root->left;
        } else {
            if (!root->right) {
                root->right = new TreeNode(val);
                return;
            }
            root = root->right;
        }
    }
}

TreeNode* buildTree(vector<int> &perm) {
    TreeNode* root = new TreeNode(perm[0]);
    for (int i = 1; i < perm.size(); i++) {
        insert(root, perm[i]);
    }
    return root;
}

bool isSame(TreeNode* a, TreeNode* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    if (a->val != b->val) return false;
    return isSame(a->left, b->left) && isSame(a->right, b->right);
}

vector<TreeNode*> generateTrees(int n) {
    vector<vector<int>> perms = genP(n);
    vector<TreeNode*> uniqueTrees;
    
    for (auto &p : perms) {
        TreeNode* root = buildTree(p);
        
        bool duplicate = false;
        for (auto existing : uniqueTrees) {
            if (isSame(existing, root)) {
                duplicate = true;
                break;
            }
        }
        
        if (!duplicate) uniqueTrees.push_back(root);
    }
    
    return uniqueTrees;
}
};
