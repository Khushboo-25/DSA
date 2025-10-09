class Solution {
public:
    int countPrimes(int n) {
        vector<int>vv(n,1);// prime
        if(n<=1)
        return 0;
        vv[0]=0;
        
        vv[1]=0;
        for(int i=2;i*i<n;i++)
        {
            if(vv[i]==1)
            {
                for(int j=i*i;j<n;j+=i)
                {
                    vv[j]=0;
                }
            }
        }
        int cn=0;
        for(int i=0;i<n;i++)
        {
            if(vv[i]==1)
            cn++;
        }
        return cn;

    }
};