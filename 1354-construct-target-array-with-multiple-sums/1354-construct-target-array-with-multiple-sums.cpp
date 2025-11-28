class Solution {
public:
    bool isPossible(vector<int>& target) 
    {
        if(target.size()==1)
        return target[0]==1;
        priority_queue<long long >pq;
        long long sm=0;
        for(auto it: target)
        {
            pq.push(it);
            sm+=it;
        }
        while(pq.top()>0)
        {
            if(pq.top()==1)
            return 1;
            long long nw=pq.top()-(sm-pq.top());
            long long rest=sm-pq.top();
            long long dv=pq.top()/rest;
            if(dv>2)
            {
                nw=pq.top()-(dv-2)*rest;
            }
            if(nw<=0)
            return 0;
            sm=sm-pq.top()+nw;
            // cout<<sm<<" "<<nw<<" ;";
            pq.pop();
            pq.push(nw);
            /*
            x>=y>=z
            s=x+y+z
            x=y+z+t
            y+z-x,y,z
            */
        }
        return 0;
        
    }
};