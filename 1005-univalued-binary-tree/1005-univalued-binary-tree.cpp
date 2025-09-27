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
    bool isUnivalTree(TreeNode* root) 
    {
        unordered_set<int>st;
        queue<TreeNode*>qt;
        qt.push(root);
        while(!qt.empty())
        {
            TreeNode* nm=qt.front();
            qt.pop();
            st.insert(nm->val);
            if(st.size()>1)
            return 0;
            if(nm->left)
            {
                qt.push(nm->left);
            }
            if(nm->right)
            qt.push(nm->right);
        }
        return 1;

        
    }
};