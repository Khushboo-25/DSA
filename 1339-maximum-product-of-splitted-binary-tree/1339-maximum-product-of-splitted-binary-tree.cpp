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

long long mod=1e9+7;
void call(long long &ans,TreeNode* root,unordered_map<TreeNode*,long long>&psum,long long &rt)
{
    if(root==NULL)
    return ;
    if(root->left)
    {
        long long ls=psum[root->left];
        long long p=((rt-ls)*1ll*ls);
        ans=max(ans,p);
    }
    if(root->right)
    {
        long long ls=psum[root->right];
        long long p=((rt-ls)*1ll*ls);
        ans=max(ans,p);
    }
    call(ans,root->left,psum,rt);
    call(ans,root->right,psum,rt);
}
long long sum(unordered_map<TreeNode*,long long>&psum,TreeNode* root)
{
    long long sm=0;
    if(root->left)
    sm+=sum(psum,root->left);
    if(root->right)
    sm+=sum(psum,root->right);
    sm+=root->val;
    return psum[root]=sm;
}
    int maxProduct(TreeNode* root) 
    {
        unordered_map<TreeNode*,long long>psum;

        long long ans=0;
        long long rootsm=sum(psum,root);
        call(ans,root,psum,rootsm);
        return ans%mod;
    }
};