class SummaryRanges {
public:
    class node {
    public:
        int s, e;
        node* next;
        node(int a, int b) {
            s = a;
            e = b;
            next = NULL;
        }
    };

    node* head;

    SummaryRanges() {
        head = new node(-8, -8); // dummy
    }

void addNum(int val) {
    node* prev = head;
    node* cur = head->next;

    while (cur && cur->e < val) {
        prev = cur;
        cur = cur->next;
    }

    // already inside prev interval
    if (prev != head && prev->s <= val && prev->e >= val)
        return;

    // already inside current interval
    if (cur && cur->s <= val && cur->e >= val)
        return;

    bool mergeLeft = (prev->e + 1 == val);
    bool mergeRight = (cur && cur->s - 1 == val);

    if (mergeLeft && mergeRight) {
        prev->e = cur->e;
        prev->next = cur->next;
    }
    else if (mergeLeft) {
        prev->e = val;
    }
    else if (mergeRight) {
        cur->s = val;
    }
    else {
        node* temp = new node(val, val);
        temp->next = cur;
        prev->next = temp;
    }
}



    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        node* cur = head->next;

        while (cur) {
            ans.push_back({cur->s, cur->e});
            cur = cur->next;
        }
        return ans;
    }
};
