/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root==NULL)
        return NULL;
        Node* ans=root;
        queue<pair<Node* ,int>> pq;
        pq.push({root,0});
        while(!pq.empty())
        {
            Node* cr= pq.front().first;
            int d=pq.front().second;
            pq.pop();
            if(!pq.empty())
            {
                if(pq.front().second==d)
                {
                    cr->next=pq.front().first;
                }
            }
            if(cr->left!=NULL)
            {
                pq.push({cr->left,d+1});

            }
            if(cr->right!=NULL)
            pq.push({cr->right,d+1});
        }
        return ans;
        
    }
};