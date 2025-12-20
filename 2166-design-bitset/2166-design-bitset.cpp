class Bitset {
public:
string s="";
int n0=0,n1=0;
    Bitset(int size) 
    {
        s="";
        n1=0;
        
        n0=size;
        while(size--)
        s+='0';
        
    }
    
    void fix(int idx) 
    {
        if(idx>=s.size())
        return;
        if(s[idx]=='0')
        {
            n1++;
            n0--;
        }
        s[idx]='1';
        
    }
    
    void unfix(int idx) 
    {
        if(idx>=s.size())
        return;
        if(s[idx]=='1')
        {
            n1--;
            n0++;
        }
        s[idx]='0';
        
    }
    
    void flip() {
        int t1=n1;
        n1=n0;
        n0=t1;
        for(auto &it:s)
        {
            if(it=='1')it='0';
            else it='1';

        }
    }
    
    bool all() 
    {
        if(n1==s.size())
        return 1;
        return 0;
    }
    
    bool one() {
        if(n1>0)
        return 1;
        return 0;
    }
    
    int count() {
       return n1;
    }
    
    string toString()
    {
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */