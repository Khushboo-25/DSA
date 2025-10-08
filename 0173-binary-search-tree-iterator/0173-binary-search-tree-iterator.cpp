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
class BSTIterator {
public:
TreeNode* ans=NULL;
int ps=0;
vector<int>in;
void update(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    update(root->left);
    in.push_back(root->val);
    update(root->right);
}
    BSTIterator(TreeNode* root) {
        ans=root;
        update(ans);
    }
    
    int next() 
    {
        if(ps<in.size())
        return in[ps++];
        return -1;
    }
    
    bool hasNext() {
        if(ps<in.size())
        return 1;
        return 0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */