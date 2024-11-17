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
void update(TreeNode* root,vector<int>&v,int &i)
{
    if(root==NULL)
    {
        return;
    }
    update(root->left,v,i);
    root->val=v[i];
    i++;
    update(root->right,v,i);
}
void inorder(TreeNode* root,vector<int>&v)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}
    TreeNode* convertBST(TreeNode* root) {
        vector<int> v;
        
        inorder(root,v);
        int n=v.size();
        for(int i=n-2;i>=0;i--)
        {
            v[i]=v[i]+v[i+1];
        }
        int i=0;
        update(root,v,i);
        return root;
    }
};