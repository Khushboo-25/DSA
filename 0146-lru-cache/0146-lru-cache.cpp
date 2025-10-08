class LRUCache {
public:
unordered_map<int,list<int>::iterator>pp1; // key->position
unordered_map<int,int>pp; // key->val
int sz=0;
list<int>st; //list
    LRUCache(int cp)
    {
        sz=cp;
    }
    int get(int key)
    {
        if(pp.find(key)==pp.end())
        return -1;
        st.erase(pp1[key]); // erase it
        st.push_front(key); // insert
        pp1[key]=st.begin(); //update position
        return pp[key]; // remain same
    }
    void put(int key, int value)
    {
        if(pp.find(key)==pp.end()) // not there
        {
            if(st.size()==sz) //full
            {
                int last=st.back();
                pp1.erase(last);
                pp.erase(last);
                st.pop_back();
            }
        }
        else
        {
            st.erase(pp1[key]);
            pp1.erase(key);
        }
        pp[key]=value;
        st.push_front(key);
        pp1[key]=st.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */