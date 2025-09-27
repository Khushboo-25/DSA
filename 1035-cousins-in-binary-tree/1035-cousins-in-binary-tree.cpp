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
void call(TreeNode* root,unordered_map<int,int>&pp,unordered_map<int,int>&hh,int h)
{
    if(root==NULL)
    return ;
    hh[root->val]=h;
    if(root->left)
    {
        pp[root->left->val]=root->val;
        call(root->left,pp,hh,h+1);
    }
    if(root->right)
    {
        pp[root->right->val]=root->val;
        call(root->right,pp,hh,h+1);
    }
}
    bool isCousins(TreeNode* root, int x, int y) 
    {
        unordered_map<int,int>pp;
        unordered_map<int,int>hh;
        call(root,pp,hh,0);
        if(hh[x]==hh[y] && pp[x]!=pp[y])
        return 1;
        return 0;
        
    }
};