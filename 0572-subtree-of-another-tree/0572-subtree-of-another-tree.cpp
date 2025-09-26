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
string call(TreeNode* root)
{
    if(root==NULL)
    {
        return "";
    }
    string ans=to_string(root->val);
    ans+='('+call(root->left)+')';
    ans+='('+call(root->right)+')';
    return ans;
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        string s1='('+call(root)+')';
        string s2='('+call(subRoot)+')';
        if(s1.find(s2)==string::npos)
        {
            return 0;
        }
        return 1;
        
    }
};