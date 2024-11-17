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
void inorder(vector<int> &nums,TreeNode* root)
{
    if(root==NULL)
    return ;
    inorder(nums,root->left);
    nums.push_back(root->val);
    inorder(nums,root->right);
}
    TreeNode* increasingBST(TreeNode* root) 
    {
        vector<int> nums;
        inorder(nums,root);
        int n=nums.size();
        TreeNode* root1=new TreeNode(nums[0]);
        TreeNode* tp=root1;
        for(int i=1;i<n;i++)
        {
            tp->right=new TreeNode(nums[i]);
            tp=tp->right;
        }
        return root1;
        
    }
};