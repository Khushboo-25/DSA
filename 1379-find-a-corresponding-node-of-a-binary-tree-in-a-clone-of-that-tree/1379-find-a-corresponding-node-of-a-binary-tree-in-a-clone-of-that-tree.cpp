/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        queue<TreeNode*>pq;
        pq.push(cloned);
        while(!pq.empty())
        {
            TreeNode* tp=pq.front();
            pq.pop();
            if(tp->val==target->val)
            return tp;
            if(tp->left)
            pq.push(tp->left);
            if(tp->right)
            pq.push(tp->right);
        }
        return NULL;
        
    }
};