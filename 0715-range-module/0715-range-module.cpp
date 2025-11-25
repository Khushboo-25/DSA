class RangeModule {
public:
vector<pair<int,int>>in;
    RangeModule() {
        
    }
    
    void addRange(int lf, int rt) {
        rt--;
        if(lf>rt)
        return;
        in.push_back({lf,rt});
        vector<pair<int,int>>nw;
        sort(in.begin(),in.end());
        int n=in.size();
        nw.push_back(in[0]);
        for(int i=1;i<n;i++)
        {
            int s1=nw.back().first;
            int e1=nw.back().second;
            int s2=in[i].first;
            int e2=in[i].second;
            if(e1>=s2-1)
            {
                int me=max(e1,e2);
                nw.pop_back();
                nw.push_back({s1,me});
            }
            else
            {
                nw.push_back({s2,e2});
            }
            
        }
        in=nw;
        // in.clear();
        // for(auto it:nw)
        // {
        //     in.push_back(it);
            // cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<"*"<<endl;
    }
    
    bool queryRange(int lf, int rt) {
        
        rt--;
        if(lf>rt)
        {
            return 0;
        }
        for(auto it: in)
        {
            int s1=it.first;
            int e1=it.second;
            if(lf>=s1 && rt<=e1)
            return 1;
        }
        return 0;
    }
    
    void removeRange(int lf, int rt) {
        rt--;
        if(lf>rt)
        return;
        // in.push_back({lf,rt});
        vector<pair<int,int>>nw;
        // sort(in.begin(),in.end());
        int n=in.size();
        // nw.push_back(in[0]);
        for(int i=0;i<n;i++)
        {
            int s1=in[i].first;
            int e1=in[i].second;
            
            if(lf>e1 || rt<s1) // non intersect
            {
                nw.push_back(in[i]);
            }
            
                
                if(lf-1>=s1 && lf<=e1) // have left
                {
                    int st=s1;
                    int et=lf-1;
                
                    nw.push_back({st,et});
                }
                if(rt+1<=e1 && rt>=s1) // have right
                {
                    int st=rt+1;
                    int et=e1;
                    nw.push_back({st,et});
                }
                
            
        }
        in=nw;
        // in.clear();
        // for(auto it:nw)
        // {
        //     in.push_back(it);
            // cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<"*||"<<endl;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */