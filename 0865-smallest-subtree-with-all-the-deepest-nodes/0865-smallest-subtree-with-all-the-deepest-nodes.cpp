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
pair<int, TreeNode*> dfs(TreeNode* root)
    {
        if (!root) return {0, nullptr};
        auto [ld, lcaL] = dfs(root->left);
        auto [rd, lcaR] = dfs(root->right);
        if (ld == rd) return {ld + 1, root};
        if (ld > rd) return {ld + 1, lcaL};
        return {rd + 1, lcaR};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};
