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
string call(TreeNode* root,unordered_map<string,int>& pp,unordered_map<string,TreeNode*>&p1)
{
    if(root==NULL)
    {
        return "";
    }
    string ans=to_string(root->val);
    string lf='('+call(root->left,pp,p1)+')';
    string rf='('+call(root->right,pp,p1)+')';
    ans+=lf+rf;
    pp[ans]++;
    p1[ans]=root;
    return ans;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        unordered_map<string,int>pp;
        unordered_map<string,TreeNode*>p1;
        string f=call(root,pp,p1);
        vector<TreeNode*>ans;
        for(auto it: pp)
        {
            if(it.second>1)
            {
                ans.push_back(p1[it.first]);
            }
        }
        return ans;
    }
};