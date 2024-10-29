class Solution {
public:
bool check(unordered_map<int,int>&pp,int i)
{
    if(i%2==0 && pp[i/2]==1)
    return 1;
    if(i%3==0 && pp[i/3]==1)
    return 1;
    if(i%5==0 && pp[i/5]==1)
    return 1;
    return 0;
}
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