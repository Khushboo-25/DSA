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
vector<int>pv;
int i=0;
void pre(TreeNode* root)
{
    if(root==NULL)
    return ;
    pre(root->left);
    pv.push_back(root->val);
    pre(root->right);
}
    BSTIterator(TreeNode* root) {
        ans=root;
        pv.clear();
        pre(root);
    }
    
    int next() {
        return pv[i++];
    }
    
    bool hasNext() 
    {
        if(i<pv.size())
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