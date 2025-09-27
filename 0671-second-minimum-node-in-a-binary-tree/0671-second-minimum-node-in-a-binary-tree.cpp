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
void call(TreeNode* root,unordered_set<int> &st)
{
    if(root==NULL)
    return ;
    st.insert(root->val);
    call(root->left,st);
    call(root->right,st);
}
    int findSecondMinimumValue(TreeNode* root) 
    {
        unordered_set<int>st;
        call(root,st);
        vector<int>st1;
        for(auto it:st)
        {
            st1.push_back(it);
        }
        sort(st1.begin(),st1.end());
        if(st1.size()<2)
        {
            return -1;
        }
        return st1[1];

        
    }
};