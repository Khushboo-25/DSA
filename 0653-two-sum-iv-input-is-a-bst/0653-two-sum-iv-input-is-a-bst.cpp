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
bool inorder(unordered_map<int,bool> &pp,TreeNode* root,int &k)
{
    if(root==NULL)
    return 0;

    if(pp[k-root->val])
    return 1;
    pp[root->val]=1;
    if(inorder(pp,root->left,k))
    return 1;
    if(inorder(pp,root->right,k))
    return 1;
    return 0;
}
    bool findTarget(TreeNode* root, int k) 
    {
        unordered_map<int,bool>pp;
        return inorder(pp,root,k);

    }
};