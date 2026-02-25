/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void call(unordered_map<TreeNode*,bool>&fp,unordered_map<TreeNode*,bool>&fq,TreeNode* root,TreeNode* &p,TreeNode*&q,TreeNode* &ans)
{
    if(root==NULL)
    return;
    if(root->val==p->val)
    fp[root]=1;
    if(root->val==q->val)
    fq[root]=1;
    call(fp,fq,root->left,p,q,ans);
    call(fp,fq,root->right,p,q,ans);
    if((root->left && fp.find(root->left)!=fp.end()) || (root->right &&fp.find(root->right)!=fp.end()))
    fp[root]=1;
    if((root->left && fq.find(root->left)!=fq.end()) || (root->right &&fq.find(root->right)!=fq.end()))
    fq[root]=1;
    if(ans==NULL && fq.find(root)!=fq.end() && fp.find(root)!=fp.end())
    {
        ans=root;
    }
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,bool>fp;
        unordered_map<TreeNode*,bool>fq;
        TreeNode* ans=NULL;
        call(fp,fq,root,p,q,ans);
        return ans;
        
    }
};