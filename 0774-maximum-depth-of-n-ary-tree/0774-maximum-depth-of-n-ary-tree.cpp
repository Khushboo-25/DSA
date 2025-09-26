/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
void call(Node* root, int &ans,int n1)
{
    if(root==NULL)
    {
        
        return;
    }
    ans=max(1+n1,ans);
    for(auto it: root->children)
    {
        
        call(it,ans,1+n1);
    }
}
    int maxDepth(Node* root) 
    {
        int ans=0;
        call(root,ans,0);
        return ans;
    }
};