/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* tt=new ListNode(-1e5);
        ListNode* root=tt;

        priority_queue<int,vector<int> ,greater<int>> pq;
        for(auto it: lists)
        {
            ListNode* prev=root;
            root->next=it;
            
            while(it)
            {
                pq.push(it->val);
                prev=it;
                it=it->next;
            }
            root=prev;

        }
        root=tt->next;
        while(root)
        {
            root->val=pq.top();
            pq.pop();
            root=root->next;
        }
        return tt->next;



        
    }
};