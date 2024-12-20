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
void update(vector<TreeNode*>&lvl)
{
    int n=lvl.size();
    int s=0,e=n-1;
    while(s<e)
    {
        int tp=lvl[s]->val;
        lvl[s]->val=lvl[e]->val;
        lvl[e]->val=tp;
        s++;
        e--;
    }
}
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        queue<TreeNode*> qt;
        int m=1;
        qt.push(root);
        while(!qt.empty())
        {
            int n=qt.size();
            vector<TreeNode*> lvl;
            while(!qt.empty())
            {
                lvl.push_back(qt.front());
                qt.pop();
            }
            if(m==-1)
            update(lvl);
            m*=-1;
            for(int i=0;i<n;i++)
            {
                if(lvl[i]->left)
                {
                    qt.push(lvl[i]->left);
                }
                if(lvl[i]->right)
                {
                    qt.push(lvl[i]->right);
                }
            }
        }
        return root;
    }
};