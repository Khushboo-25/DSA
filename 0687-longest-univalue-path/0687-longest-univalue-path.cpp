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
vector<int> update(TreeNode* root)
{
    if(root==NULL)
    {          ///cr,cf,mf
        return {INT_MIN,0,0};
    }
    if(root->left==NULL && root->right==NULL)
    return {root->val,1,1};
    
    vector<int> lf=update(root->left);
    vector<int> rf=update(root->right);
    int cr=root->val;
    if(lf[0]==cr && rf[0]==cr)
    {
        
        int cf=max(rf[1],lf[1])+1;
        int mf=max({lf[2],rf[2],rf[1]+lf[1]+1});
        return {cr,cf,mf};
    }
    else if(lf[0]==cr)
    {
        int cf=lf[1]+1;
        int mf=max({lf[2],cf,rf[2]});
        return {cr,cf,mf};
    }
    else if(rf[0]==cr)
    {
        int cf=rf[1]+1;
        int mf=max({rf[2],cf,lf[2]});
        return {cr,cf,mf};

    }
    int cf=1;
    int mf=max({lf[2],rf[2],cf});
    return {cr,cf,mf};
}
    int longestUnivaluePath(TreeNode* root) 
    {
        if(root==NULL)
        return 0;
        vector<int> p=update(root);
        return p[2]-1;

        
    }
};