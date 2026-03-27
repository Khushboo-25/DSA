class Solution {
public:

    int nthUglyNumber(int n) 
    {
        if(n==1)
        return 1;
        unordered_map<long long,int>pp;
        pp[1]=1;
        int t=1;
        long long ans=1;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        pq.push(1);
        while(!pq.empty() && t<=n)
        {
            int tp=pq.top();
            pq.pop();
                t++;
                if(t==n+1)
                return tp;
            if(!(pp[tp*1ll*2]>0))
            {
                pq.push(tp*1ll*2);
                pp[tp*1ll*2]=1;
            }
            if(!(pp[tp*1ll*3]>0))
            {
                pq.push(tp*1ll*3);
                pp[tp*1ll*3]=1;
            }
            if(!(pp[tp*1ll*5]>0))
            {
                pq.push(tp*1ll*5);
                pp[tp*1ll*5]=1;
            }
        }
        
        return -1;
    }
};