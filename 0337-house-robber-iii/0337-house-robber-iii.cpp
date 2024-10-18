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
int call(TreeNode* root,int tk,map<pair<TreeNode*,int>,int>&dp)
{
    if(root==NULL)
    return 0;
    if(dp.find({root,tk})!=dp.end())
    return dp[{root,tk}];
    int sum=0;
    if(tk==1) //take
    {
        int left=call(root->left,0,dp);
        int right=call(root->right,0,dp);
        sum=max(sum,root->val+left+right);
    }
    else
    {
        int left1=max(call(root->left,0,dp),call(root->left,1,dp));
        int right1=max(call(root->right,0,dp),call(root->right,1,dp));
        sum=max(sum,left1+right1);
    }
    return dp[{root,tk}]=sum;
}
    int rob(TreeNode* root) 
    {
        map<pair<TreeNode*,int>,int>dp;
       if(root==NULL)
       return 0;
       return max(call(root,1,dp),call(root,0,dp));
    }
};