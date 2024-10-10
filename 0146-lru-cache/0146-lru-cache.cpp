class LRUCache {
public:
  unordered_map<int, list<int>::iterator> pp1;
      unordered_map<int,int>pp;
      int sz=0;
      list<int> st;
    LRUCache(int cap) {
        sz=cap;
    }
    
    int get(int key) {
        
        if(pp.find(key)!=pp.end())
        {
            st.erase(pp1[key]);
        st.push_front(key);
        pp1[key]=st.begin();
        return pp[key];
        }
        return -1;
        
        // your code here
    }

    // Function for storing key-value pair.
    void put(int key, int value) 
    {
        if(pp.find(key)==pp.end())
        {
            if(pp.size()==sz)
            {
                int last=st.back();
                st.pop_back();
                pp.erase(last);
                pp1.erase(last);
            }
        }
        else
        {
            st.erase(pp1[key]);
            pp.erase(key);
            pp1.erase(key);
        }
        pp[key]=value;
        st.push_front(key);
        pp1[key]=st.begin();
        
        // your code here
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */