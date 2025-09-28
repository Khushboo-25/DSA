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

    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        return dfs(root).second;
    }
};
