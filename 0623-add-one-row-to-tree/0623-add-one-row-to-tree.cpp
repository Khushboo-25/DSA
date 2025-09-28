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
    TreeNode* addOneRow(TreeNode* root, int val, int d) 
    {
        if(d==1)
        {
            TreeNode* tp=new TreeNode(val);
            tp->left=root;
            return tp;
        }
        queue<pair<int,TreeNode*>>qt;
        vector<TreeNode*>up;
        qt.push({1,root});
        while(!qt.empty())
        {
            int dp=qt.front().first;
            TreeNode* node=qt.front().second;
            qt.pop();
            if(dp<d-1)
            {
                if(node->left)
                {
                    qt.push({dp+1,node->left});
                }
                if(node->right)
                {
                    qt.push({dp+1,node->right});
                }
            }
            if(dp==d-1)
            {
                up.push_back(node);
            }
        }
        // cout<<up.size()<<" ";
        for(auto &it: up)
        {
            TreeNode* lf=it->left;
            TreeNode* rf=it->right;
            it->left=new TreeNode(val);
            it->right=new TreeNode(val);
            it->left->left=lf;
            it->right->right=rf;
        }
        return root;


        
    }
};