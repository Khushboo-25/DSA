class MedianFinder {
public:
    vector<int> pp;
    void addNum(int num) 
    {
        pp.insert(lower_bound(pp.begin(), pp.end(), num),num);
    }
    double findMedian() 
    {
        // sort(pp.begin(),pp.end());
        int n=pp.size();
        if(n%2)
        {
            return pp[n/2];
        }
        return (pp[n/2]+pp[n/2-1])/(2.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */