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
void call(TreeNode* root,vector<int>&in)
{
    if(root==NULL) return ;
    call(root->left,in);
    in.push_back(root->val);
    call(root->right,in);
}
TreeNode* update(int s,int e,vector<int>&in)
{
    if(s>e)
    return NULL;
    int m=s+(e-s)/2;
    TreeNode* root=new TreeNode(in[m]);
    root->left=update(s,m-1,in);
    root->right=update(m+1,e,in);
    return root;

}
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<int>in;
        call(root,in);
        // TreeNode* ans=new TreeNode(0);
        return update(0,in.size()-1,in);
        
    }
};