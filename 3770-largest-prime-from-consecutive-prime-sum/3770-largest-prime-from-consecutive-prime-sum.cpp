class Solution {
public:
    int largestPrime(int n) 
    {
        if(n<2)
        return 0;
        vector<int>pv(n+1,1);
        pv[0]=0;
        pv[1]=0;
        vector<int>pr;
        for(int j=2;j<=n;j++)
        {
            if(pv[j]==1)
            {
                pr.push_back(j);
                
                for(long long k = 1LL * j * j; k <= n; k += j)
                pv[k]=0;
            }
        }
        int n1=pr.size();
        int ans=0;
        int s=0;
        for(int i=0;i<n1;i++)
        {
            if(s+pr[i]<=n)
            {
                s+=pr[i];
                if(pv[s]==1)
                ans=s;
            }
            else
            break;
            
            
        }
        return ans;
    }
};