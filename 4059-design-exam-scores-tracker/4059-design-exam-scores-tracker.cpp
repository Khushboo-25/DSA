class ExamTracker {
public:
vector<int>st;
vector<long long>sr;
    ExamTracker() {
        
    }
    
    void record(int time, int score) 
    {
        if(st.empty())
        {
            st.push_back(time);
            sr.push_back(score);
        }
        else
        {
            st.push_back(time);
            long long nw=sr.back()+score;
            sr.push_back(nw);
        }

        
    }
    
    long long totalScore(int startTime, int endTime) {
        int si=lower_bound(st.begin(),st.end(),startTime)-st.begin();
        int ei=(upper_bound(st.begin(),st.end(),endTime)-st.begin())-1;
        // cout
        long long ans=0;
        if(ei>=0)
        ans+=sr[ei];
        if(si-1>=0)
        ans-=sr[si-1];
        return ans;

    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */