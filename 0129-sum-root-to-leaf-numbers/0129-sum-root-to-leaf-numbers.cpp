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
void inorder(TreeNode* root,int d,int &s)
{
    if(root==NULL)
    return;
    if(root->left==NULL && root->right==NULL)
    {
        s+=d;
    }
    if(root->left)
    inorder(root->left,d*10+root->left->val,s);
    if(root->right)
    inorder(root->right,d*10+root->right->val,s);
}
    int sumNumbers(TreeNode* root) 
    {
        if(root==NULL)
        return 0;
        int s=0;
        int d=root->val;
        inorder(root,d,s);
        return s;
    }
};