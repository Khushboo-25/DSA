class KthLargest {
public:
multiset<int>st;
int k1=0;
    KthLargest(int k, vector<int>& nums)
    {
        k1=k;
        st.clear();
        for(auto it:nums)
        st.insert(it);
    }
    
    int add(int val)
    {
        st.insert(val);
        int n=st.size();
        if(n<k1)
        return -1;
        auto it=st.begin();
        advance(it,n-k1);
        return *it;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */