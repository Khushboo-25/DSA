class LRUCache {
public:
list<int> cache; //cache
unordered_map<int,list<int>::iterator>psn; //key->position
unordered_map<int,int>pp; // key->value
int sz=0;
    LRUCache(int cap) 
    {
        sz=cap;
    }
    
    int get(int key) 
    {
        if(psn.find(key)==psn.end()) // not there
        {
            return -1;
        }
        else
        {
            cache.erase(psn[key]);
            psn.erase(key);
            cache.push_front(key);
            psn[key]=cache.begin();
            return pp[key];
        }
    }
    
    void put(int key, int value) 
    {
        if(psn.find(key)==psn.end()) // not there
        {
            if(cache.size()==sz) // full
            {
                int last=cache.back();
                cache.erase(psn[last]);
                psn.erase(last);
                pp.erase(last);
            }
        }
        else // there
        {
            cache.erase(psn[key]);
            psn.erase(key);
        }
        cache.push_front(key);
        psn[key]=cache.begin();
        pp[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */