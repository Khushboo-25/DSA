class Solution {
public:
    long long removeZeros(long long n) 
    {
        long long ans=0;
        long long p=1;
        while(n>0)
        {
            if(n%10!=0)
            {
                ans=ans+(n%10)*p;
                p*=10;
            }
            n=n/10;
        }
        return ans;
        
    }
};