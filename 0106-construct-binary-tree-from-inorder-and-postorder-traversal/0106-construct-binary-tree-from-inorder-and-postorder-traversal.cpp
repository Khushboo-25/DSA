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
    TreeNode* cons(vector<int> &in,vector<int> &pos, int s,int e,int &i,int n)
    {
        if(s>e || i<0)
        return NULL;
        int ele=pos[i];
        i--;
        TreeNode* root=new TreeNode(ele);
        int ind=-1;
        for(int j=s;j<=e;j++)
        {
            if(in[j]==ele)
            {
                ind=j;
                break;
            }
        }
        root->right=cons(in,pos,ind+1,e,i,n);
        root->left=cons(in,pos,s,ind-1,i,n);
        // swap(root->left,root->right);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& pos) {
        
        int n=in.size();
        int i=n-1;
        return cons(in,pos,0,n-1,i,n);
    }
};