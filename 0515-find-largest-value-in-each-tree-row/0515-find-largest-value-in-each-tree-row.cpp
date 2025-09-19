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
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> ans;
        if(root==NULL)
        return ans;
        queue<pair<TreeNode*,int>> qt;
        qt.push({root,0});
        while(!qt.empty())
        {
            TreeNode* tp=qt.front().first;
            int lv=qt.front().second;
            qt.pop();
            if(lv<ans.size())
            {
                ans[lv]=max(ans[lv],tp->val);
            }
            else
            ans.push_back(tp->val);
            if(tp->left)
            {
                qt.push({tp->left,lv+1});
            }
            if(tp->right)
            {
                qt.push({tp->right,lv+1});
            }
        }
        return ans;
        
    }
};