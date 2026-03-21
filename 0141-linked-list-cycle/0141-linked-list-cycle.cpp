/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)
        return 0;
        ListNode* s1=head;
        ListNode* s2=head->next;
        while(s1!=NULL && s2!=NULL)
        {
            if(s1==s2)
            return 1;
            s1=s1->next;
            s2=s2->next;
            if(s2)
            {
                s2=s2->next;
            }
        }
        return 0;
        
    }
};