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
    bool evaluateTree(TreeNode* root) 
    {
        if(root==NULL)
        return 0;
        if(root->left==NULL && root->right==NULL)
        {
            return root->val;
        }

        bool lf=evaluateTree(root->left);
        bool rf=evaluateTree(root->right);
        if(root->val==2)
        {
            return lf|rf;
        }
        if(root->val==3)
        {
            return lf & rf;
        }
        return root->val;
        
    }
};