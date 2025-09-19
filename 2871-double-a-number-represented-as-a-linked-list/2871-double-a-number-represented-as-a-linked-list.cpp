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
int call(ListNode* head)
{
    if(head==NULL)
    return 0;
    
    head->val=call(head->next)+head->val*2;
    int cr=head->val/10;
    head->val%=10;
    return cr;
}
    ListNode* doubleIt(ListNode* head) 
    {
        int cr=call(head);
        ListNode* ans=new ListNode(cr);
        ans->next=head;
        if(cr>0)
        {
            return ans;
        }
        return ans->next;
    }
};