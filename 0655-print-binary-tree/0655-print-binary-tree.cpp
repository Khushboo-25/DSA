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
void call(int h,TreeNode* root,vector<int>&in,unordered_map<int,int>&ht,int &mh,int &nc)
{
    if(root==NULL)
    return;
    ht[root->val]=h;
    mh=max(mh,h);
    nc|=1<<h;
    call(h+1,root->left,in,ht,mh,nc);
    in.push_back(root->val);
    call(h+1,root->right,in,ht,mh,nc);
}
void update(TreeNode* root,int s,int e,int rw,vector<vector<string>>&ans)
{
    if(root==NULL || s>e)
    return ;
    int m=s+(e-s)/2;
    string st=to_string(root->val);
    ans[rw][m]=st;
    update(root->left,s,m-1,rw+1,ans);
    update(root->right,m+1,e,rw+1,ans);
}
    vector<vector<string>> printTree(TreeNode* root) 
    {
        vector<int>in;
        unordered_map<int,int>ht;
        int mh=0;
        
        int nc=0;
        call(0,root,in,ht,mh,nc);

        vector<vector<string>>ans(mh+1,vector<string>(nc,""));
        update(root,0,nc-1,0,ans);
        return ans;
    }
};