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
// bool call()
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        if(root1==NULL && root2==NULL)
        return 1;
        if(root1==NULL|| root2==NULL)
        return 0;
        if(root1->val!=root2->val)
        {
            return 0;
        }
        if(flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left))
        return 1;
        else if(flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right))
        return 1;
        return 0;
    }
};