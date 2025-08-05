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
    ListNode* partition(ListNode* head, int x) {
        ListNode* st=new ListNode(0);
        ListNode* nt=new ListNode(0);
        ListNode* tp1=st;
        ListNode* tp2=nt;
        while(head)
        {
            if(head->val<x)
            {
                tp1->next=head;
                head=head->next;
                tp1=tp1->next;
                tp1->next=NULL;
            }
            else
            {
                tp2->next=head;
                head=head->next;
                tp2=tp2->next;
                tp2->next=NULL;
            }

        }
        tp1->next=nt->next;
        return st->next;
    }
};