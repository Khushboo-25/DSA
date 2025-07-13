/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node*,Node*>pp;
    Node* cloneGraph(Node* node) 
    {
        if(node==NULL)
        return NULL;
        if(pp.find(node)!=pp.end())
        return pp[node];
        Node* cl=new Node(node->val);
        pp[node]=cl;
        for(auto it: node->neighbors)
        {
            Node* nw=cloneGraph(it);
            cl->neighbors.push_back(nw);
            
            
        }
        return cl;
        
    }
};