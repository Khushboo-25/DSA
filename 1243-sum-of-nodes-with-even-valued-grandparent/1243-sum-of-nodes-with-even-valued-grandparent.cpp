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
void call(TreeNode* p, TreeNode* g,int &ans)
{
    if(g->val%2==0)
    {
        if(p->left)
        ans+=p->left->val;
        if(p->right)
        ans+=p->right->val;
    }
    if(p->left)
    call(p->left,p,ans);
    if(p->right)
    call(p->right,p,ans);
}
    int sumEvenGrandparent(TreeNode* root) 
    {
        int ans=0;
        if(root==NULL)
        return 0;
        if(root->left)
        call(root->left,root,ans);
        if(root->right)
        call(root->right,root,ans);
        return ans;
        
    }
};