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

int call(TreeNode* root,int &ans)
{
    if(root==NULL)
    {
        return 0;
    }
    int s=0;
    int lf=call(root->left,ans);
    int rf=call(root->right,ans);
    s+=root->val+lf+rf;
    ans+=abs(lf-rf);
    return s;
}
    int findTilt(TreeNode* root) {
        int ans=0;
       int s= call(root,ans);
       return ans;
        
    }
};