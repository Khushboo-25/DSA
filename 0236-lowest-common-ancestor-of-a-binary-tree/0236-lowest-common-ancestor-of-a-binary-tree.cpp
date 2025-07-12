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
void call(TreeNode* p,TreeNode* root ,unordered_map<TreeNode*,TreeNode*>&pp)
{
    if(root==NULL)
    {
        return;
    }
    pp[root]=p;
    call(root,root->left,pp);
    call(root,root->right,pp);
    
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,TreeNode*>pp;
        call(NULL,root,pp);
        unordered_map<TreeNode*,bool>vv;
        while(p!=NULL || q!=NULL)
        {
            
            if(p!=q)
            {
                if(p!=NULL)
                {
                    vv[p]=1;
                    p=pp[p];
                }
                if(q!=NULL)
                {
                    vv[q]=1;
                    q=pp[q];
                }
                
                if(vv[p]==1)
                return p;
                if(vv[q]==1)
                return q;
            }
            else
            return p;
        }
        return NULL;
    }
};