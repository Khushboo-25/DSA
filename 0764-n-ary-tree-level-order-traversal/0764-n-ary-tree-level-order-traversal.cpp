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
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        if(root==NULL)
        return ans;
        queue<Node*> qt;
        qt.push(root);
        while(!qt.empty())
        {
            int tn=qt.size();
            vector<int> lv;
            while(tn--)
            {
                Node* cr=qt.front();
                if(cr->children.size()>0)
                {
                    for(auto it: cr->children)
                    {
                        qt.push(it);
                    }
                }
                lv.push_back(cr->val);
                qt.pop();
            }
            ans.push_back(lv);
        }
        return ans;
        
    }
};