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
void call(int mx, TreeNode* root, int &ans)
{
    if(root==NULL)
    return;
    if(mx<=root->val)
    {
        ans++;
    }
    mx=max(root->val,mx);
    call(mx,root->left,ans);
    call(mx,root->right,ans);
}
    int goodNodes(TreeNode* root) 
    {
        int ans=0;
        call(-1e5,root,ans);
        return ans;
    }
};