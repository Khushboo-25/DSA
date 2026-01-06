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

void inorder(TreeNode* root,int h,vector<pair<int,int>> &v)
{
    if(root==NULL)
    return;
    inorder(root->left,h+1,v);
    v.push_back({root->val,h});
    inorder(root->right,h+1,v);
}
//level order approach
    int helper(TreeNode *root)
    {
        int sum=INT_MIN;
        int res=0;
        int curr=0;
        queue<TreeNode*> q;
        if(root==NULL)
        return 0;
        q.push(root);
        int x=1;
        while(!q.empty())
        {
            int size=q.size();
            curr=0;
            for(int i=0;i<size;i++ )
            {
                TreeNode* temp=q.front();
                curr+=temp->val;
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
                q.pop();
            }
            if(curr>sum)
            {
                sum=curr;
                res=x;
            }
            x++;
        }
        return res;
    }
    int maxLevelSum(TreeNode* root) 
    {
        return helper(root);
        vector<pair<int,int>> v;
        int h=1;
        inorder(root,h,v);
        // sort(v.begin(),v.end(),sortbysec());
        map<int,int> p;
        int ans=INT_MIN;
        for( auto it: v)
        {
            p[it.second]+=it.first;
        }
        for( auto it: v)
        {
            ans=max(ans,p[it.second]);
        }
        for(auto it:p)
        {
            // cout<<it.first<<" "<<it.second<<" "<<ans<<endl;
            if(it.second==ans)
            return it.first;
        }
    return 0;

    }
};