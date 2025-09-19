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
int call(TreeNode* root,unordered_map<int,int>&pp)
{
    int sum=0;
    if(root==NULL)
    return sum;
    sum+=root->val;
    sum+=call(root->left,pp);
    sum+=call(root->right,pp);
    pp[sum]++;
    return sum;
}
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        unordered_map<int,int>pp;
        int sm=call(root,pp);
        // pp[sm]++;
        vector<pair<int,int>>v1;
        for(auto it: pp)
        {
            //f,val
            v1.push_back({it.second,it.first});
        }
        sort(v1.rbegin(),v1.rend());
        int f=v1[0].first;//  mf
        vector<int>ans;
        for(auto it:v1)
        {
            if(it.first==f)
            ans.push_back(it.second);
        }
        return ans;

        
    }
};