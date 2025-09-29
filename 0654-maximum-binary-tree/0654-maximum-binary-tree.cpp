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
TreeNode* call(int s,int e,vector<int> &nums)
{
    if(s>e)
    {
        return NULL;
    }
    int mx=*max_element(nums.begin()+s,nums.begin()+e+1);
    int i=-1;
    for(int k=s;k<=e;k++)
    {
        if(mx==nums[k])
        {
            i=k;
            break;
        }

    }
    TreeNode* ans=new TreeNode(mx);
    ans->left=call(s,i-1,nums);
    ans->right=call(i+1,e,nums);
    return ans;
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        
        int s=0,e=nums.size()-1;
        TreeNode* ans=call(s,e,nums);
        return ans;

        
    }
};