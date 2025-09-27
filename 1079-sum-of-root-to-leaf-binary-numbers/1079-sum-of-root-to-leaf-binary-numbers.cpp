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
void call(TreeNode* root,int num,int &ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->val==0)
    {
        num*=2;
    }
    else
    {
        num=num*2+1;
    }
    if(root->left==NULL && root->right==NULL) //leaf
    {
        ans+=num;
        return;
    }
    call(root->left,num,ans);
    call(root->right,num,ans);
}
    int sumRootToLeaf(TreeNode* root) 
    {
        int ans=0;
        call(root,0,ans);
        return ans;
        
    }
};