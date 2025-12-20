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
int res = 0;
pair<int,int> call(TreeNode* root)
{
    if(root==NULL)
    {
        return {0,0};
    }
    pair<int,int>lf=call(root->left);
    pair<int,int>rf=call(root->right);
    int lef=1+rf.second;
    int ref=1+lf.first;
    res=max({res,lef,ref});
    // cout<<lef<<" "<<ref<<" "<<root->val<<endl;
    return {lef,ref};
}
    int longestZigZag(TreeNode* root) 
    {

        pair<int,int>ans=call(root);
        return res-1;
        
    }
};

