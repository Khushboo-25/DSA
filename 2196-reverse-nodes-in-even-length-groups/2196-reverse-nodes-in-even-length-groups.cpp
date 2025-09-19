class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* ans = NULL;
        while (head) {
            ListNode* tp = head;
            head = head->next;
            tp->next = ans;
            ans = tp;
        }
        return ans;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<pair<int, ListNode*>> vv;
        int rl = 1;
        int cn = 0;
        ListNode* pv = head;
        ListNode* cur = head;

        while (cur) {
            cn++;
            if (cn == rl) {
                vv.push_back({cn, pv});
                if (cur->next) {
                    ListNode* tp = cur->next;
                    pv = tp;
                    cur->next = NULL; // break group
                    cur = tp;
                } else {
                    cur = NULL;
                }
                cn = 0;
                rl++;
            } else {
                cur = cur->next; // <---- THIS IS IMPORTANT
            }
        }

        if (cn != 0) vv.push_back({cn, pv});

        ListNode* ans = new ListNode(0);
        pv = ans;

        for (auto it : vv) {
            if (it.first % 2 == 0) it.second = reverseList(it.second);
            pv->next = it.second;
            while (it.second) {
                pv = it.second;
                it.second = it.second->next;
            }
        }
        return ans->next;
    }
};
