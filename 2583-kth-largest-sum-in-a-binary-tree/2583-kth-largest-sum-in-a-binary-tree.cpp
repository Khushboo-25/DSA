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
void call(int h,TreeNode* root,unordered_map<int, long long>&pp)
{
    if(root==NULL)
    return ;
    pp[h]+=root->val;
    call(h+1,root->left,pp);
    call(h+1,root->right,pp);
}
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        unordered_map<int ,long long>pp;
        call(0,root,pp);
        int n=pp.size();
        vector<long long>hq;
        for(auto it:pp)
        {
            hq.push_back(it.second);
        }
        sort(hq.rbegin(),hq.rend());
        if(hq.size()<k)
        return -1;
        return hq[k-1];
    }
};