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
vector<int> call(ListNode* tp,vector<int> &ans)
{
    if(tp==NULL)
    {
        return {};
    }
    vector<int> vv=call(tp->next,ans);
    while(!vv.empty() && vv.back()<=tp->val)
    {
        vv.pop_back();
    }
    if(!vv.empty())
    ans.push_back(vv.back());
    else
    ans.push_back(0);
    vv.push_back(tp->val);
    return vv;
}
    vector<int> nextLargerNodes(ListNode* head) 
    {
        
        vector<int>ans;
        vector<int> vv=call(head,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};