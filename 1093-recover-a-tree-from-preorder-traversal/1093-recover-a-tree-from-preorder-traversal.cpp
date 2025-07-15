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
void call(int &i,int d,int &n,string &tt,TreeNode* &ans)
{
    if(i>=n)
    return ;
    int cd=0;
    int pv=i;
    while(tt[i]=='-')
    {
        cd++;
        i++;
    }
    int val=0;
    while(i<n && tt[i]!='-')
    {
        val=(val*10)+(tt[i]-'0');
        i++;
    }
    if(d>cd)
    {
        i=pv;
        return;
    }
    
    if(d==cd)
    {
        ans=new TreeNode(val);
        cout<<val<<" ";
        
        call(i,d+1,n,tt,ans->left);
        call(i,d+1,n,tt,ans->right);
    }
    
    // i++;
    
    
    // else
    // i++;
    
}
    TreeNode* recoverFromPreorder(string &tt) 
    {
        int n=tt.size();
        TreeNode* ans;
        int i=0;
        call(i,0,n,tt,ans);
        return ans;
        
    }
};