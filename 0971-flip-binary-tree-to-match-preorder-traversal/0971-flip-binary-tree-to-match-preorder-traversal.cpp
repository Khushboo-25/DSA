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
void update(TreeNode* root,unordered_map<int,int>&pre,vector<int>&ans)
{
    if(root==NULL)
    {
        return ;
    }
    
    if(root->left && root->right)
    {
        int lf=root->left->val;
        int rf=root->right->val;
        if(pre[lf]>pre[rf])
        {
            ans.push_back(root->val);
            TreeNode* r_f=root->left;
            TreeNode* l_f=root->right;
            root->left=l_f;
            root->right=r_f;
        }
        update(root->left,pre,ans);
        update(root->right,pre,ans);
    }
    else if(root->left)
    {
        // int lf=root->left->val;
        // int rt=root->val;
        // if(pre[lf]<pre[rt])
        // {
        //     ans.push_back(root->val);
        //     TreeNode* r_f=root->left;
        //     TreeNode* l_f=root->right;
        //     root->left=l_f;
        //     root->right=r_f;
        // }
        update(root->left,pre,ans);
    }
    else if(root->right)
    {
        // int lt=root->val;
        // int rf=root->right->val;
        // if(pre[lt]>pre[rf])
        // {
        //     ans.push_back(root->val);
        //     TreeNode* r_f=root->left;
        //     TreeNode* l_f=root->right;
        //     root->left=l_f;
        //     root->right=r_f;
        // }
        update(root->right,pre,ans);
    }
}
void call2(TreeNode* root,vector<int>&pre)
{
    if(root==NULL)
    return ;
    pre.push_back(root->val);
    call2(root->left,pre);
    call2(root->right,pre);

}
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& order) 
    {
        unordered_map<int,int>pre;
        int n=order.size();
        for(int i=0;i<n;i++)
        {
            pre[order[i]]=i;
        }
        vector<int>ans;
        update(root,pre,ans);
        vector<int>nw;
        call2(root,nw);
        for(int i=0;i<n;i++)
        {
            if(nw[i]!=order[i])
            return {-1};
        }
        
        return ans;
        
    }
};