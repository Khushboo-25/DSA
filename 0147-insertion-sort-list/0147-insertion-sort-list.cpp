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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* root=head;
        priority_queue<int> q;
        stack<int> st;
        
        while(head!=NULL)
        {
            q.push(head->val);
            head=head->next;
        }
        head=root;
        while(!q.empty())
        {
            st.push(q.top());
            q.pop();
        }
        while(head!=NULL)
        {
            head->val=st.top();
            st.pop();
            head=head->next;
        }
        return root;
    }
};