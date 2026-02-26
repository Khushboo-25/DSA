class Solution {
public:
    int countPrimes(int n) 
    {
        if(n<=1)
        return 0;
        vector<int>vv(n+1,1);
        vv[0]=0;
        vv[1]=0;
        for(int i=2;i<=n;i++)
        {
            if(vv[i]==1)
            {
                for(int j=min(n*1ll,i*1ll*i);j<=n;j+=i)
                {
                    vv[j]=0;
                }
            }
        }
        int ans=0;
        for(auto it:vv)
        {
            ans+=it;
        }
        return ans;
        
    }
};