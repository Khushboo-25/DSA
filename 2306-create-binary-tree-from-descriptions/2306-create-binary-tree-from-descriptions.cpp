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
    TreeNode* createBinaryTree(vector<vector<int>>& dr) 
    {
        unordered_map<int,TreeNode*>pp;
        unordered_map<int,int>pf;
        // TreeNode* head=NULL;
        for(auto it: dr)
        {
            int node=it[0];
            int child=it[1];
            pf[child]=1;
            int lf=1;
            if(it[2]==0)
            {
                lf=0;
            }
            if(pp.find(node)==pp.end())
            {
                TreeNode* tp=new TreeNode(node);
                pp[node]=tp;
                
                if(lf)
                {
                    if(pp.find(child)==pp.end())
                    {
                        TreeNode* lf=new TreeNode(child);
                        pp[child]=lf;
                        tp->left=lf;
                    }
                    else
                    {
                        TreeNode* lf=pp[child];
                        tp->left=lf;
                    }
                }
                else
                {
                    if(pp.find(child)==pp.end())
                    {
                        TreeNode* rf=new TreeNode(child);
                        pp[child]=rf;

                        tp->right=rf;
                    }
                    else
                    {
                        TreeNode* rf=pp[child];
                        
                        tp->right=rf;
                    }
                }
            }
            else
            {
                TreeNode* tp=pp[node];

                if(lf)
                {
                    if(pp.find(child)==pp.end())
                    {
                        TreeNode* lf=new TreeNode(child);
                        pp[child]=lf;
                        tp->left=lf;
                    }
                    else
                    {
                        TreeNode* lf=pp[child];
                        tp->left=lf;
                    }
                }
                else
                {
                    if(pp.find(child)==pp.end())
                    {
                        TreeNode* rf=new TreeNode(child);
                        pp[child]=rf;
                        tp->right=rf;
                    }
                    else
                    {
                        TreeNode* rf=pp[child];
                        tp->right=rf;
                    }
                }
            }
            

        }
        for(auto it:pp)
        {
            if(pf[it.first]!=1)
            return it.second;
        }
        return NULL;
        
    }
};