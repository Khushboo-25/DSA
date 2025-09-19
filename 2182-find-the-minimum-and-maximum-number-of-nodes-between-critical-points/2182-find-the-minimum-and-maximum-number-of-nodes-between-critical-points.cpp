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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) 
    {
        int prev=head->val;
        vector<int> ans;
        head=head->next;
        int i=1;
        while(head->next)
        {
            int next=-1;
            next=head->next->val;
            if(head->val>prev && head->val>next)
            {
                ans.push_back(i);
            }
            else if(head->val<prev && head->val<next)
            {
                ans.push_back(i);
            }
            prev=head->val;
            head=head->next;
            i++;
        }
        if(ans.size()<=1)
        return {-1,-1};
        
        int mn=INT_MAX;
        // for(auto it: ans)
        // cout<<it<<" ";
        for(int i=1;i<ans.size();i++)
        {
            mn=min(ans[i]-ans[i-1],mn);
        }
        return {mn,ans[ans.size()-1]-ans[0]};
        
    }
};