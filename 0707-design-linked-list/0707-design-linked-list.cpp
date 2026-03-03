class MyLinkedList {
public:
    class List {
    public:
        int val;
        List* next;
        List(int d) {
            val = d;
            next = NULL;
        }
    };

    List* root;
    int sz;

    MyLinkedList() {
        root = NULL;
        sz = 0;
    }

    int get(int index) {
        if(index < 0 || index >= sz) return -1;

        List* cur = root;
        while(index--) {
            cur = cur->next;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        List* node = new List(val);
        node->next = root;
        root = node;
        sz++;
    }

    void addAtTail(int val) {
        List* node = new List(val);
        if(root == NULL) {
            root = node;
        } else {
            List* cur = root;
            while(cur->next) {
                cur = cur->next;
            }
            cur->next = node;
        }
        sz++;
    }

    void addAtIndex(int index, int val) {
        if(index < 0 || index > sz) return;

        if(index == 0) {
            addAtHead(val);
            return;
        }

        List* cur = root;
        for(int i = 0; i < index - 1; i++) {
            cur = cur->next;
        }

        List* node = new List(val);
        node->next = cur->next;
        cur->next = node;
        sz++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= sz) return;

        if(index == 0) {
            List* temp = root;
            root = root->next;
            delete temp;
        } else {
            List* cur = root;
            for(int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            List* temp = cur->next;
            cur->next = temp->next;
            delete temp;
        }
        sz--;
    }
};