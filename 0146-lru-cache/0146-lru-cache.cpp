class LRUCache {
public:
int sz=0;
list<int>cache;
unordered_map<int,list<int>::iterator>pt;
unordered_map<int,int>pp;
    LRUCache(int cap) {
        sz=cap;
    }
    
    int get(int key) {
        if(pp.find(key)!=pp.end())
        {
            // int value=pp[key];
            cache.erase(pt[key]);
            cache.push_front(key);
            pt[key]=cache.begin();
            // pp[key]=value;
            return pp[key];
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        if(pp.find(key)!=pp.end()) //already in cache
        {
            // first remove
            cache.erase(pt[key]);
            pt.erase(key);
        }
        else
        {
            if(cache.size()>=sz)
            {
                int it=cache.back();
                cache.erase(pt[it]);
                pt.erase(it);
                pp.erase(it);
            }
        }
        
        cache.push_front(key);
        pt[key]=cache.begin();
        pp[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */