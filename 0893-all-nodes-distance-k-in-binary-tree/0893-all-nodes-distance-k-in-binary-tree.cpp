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
void call(TreeNode* root,vector<vector<int>>&adj)
{
    if(root==NULL)
    {
        return ;
    }
    int x=root->val;
    if(root->left)
    {
        int y=root->left->val;
        adj[x].push_back(y);
        adj[y].push_back(x);
        call(root->left,adj);
    }
    if(root->right)
    {
        int y=root->right->val;
        adj[x].push_back(y);
        adj[y].push_back(x);
        call(root->right,adj);
    }
}
void bfs(int &cn,vector<vector<int>>&adj,int &k,vector<int>&ans,vector<int>&vv)
{
    queue<pair<int,int>>qt;
    qt.push({cn,k});
    vv[cn]=1;
    while(!qt.empty())
    {
        int x=qt.front().first;
        int kn=qt.front().second;
        qt.pop();
        if(kn==0)
        {
            ans.push_back(x);
        }
        for(auto it:adj[x])
        {
            if(vv[it]==0)
            {
                qt.push({it,kn-1});
                vv[it]=1;
            }
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        int n=501;
        vector<vector<int>>adj(n);
        call(root,adj);
        vector<int>ans;
        vector<int>vv(501,0);
        bfs(target->val,adj,k,ans,vv);
        return ans;
    }
};