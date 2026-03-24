class MedianFinder {
public:
    multiset<int>st;
    void addNum(int num) 
    {
        st.insert(num);
    }
    double findMedian() 
    {
        // sort(pp.begin(),pp.end());
        int n=st.size();
        
            auto it=st.begin();
            advance(it,(n-1)/2);
            double x=*it;
            if(n%2==0)
            {
                advance(it,1);
                x+=*it;
                return x/2.0;
            }
            return x;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */