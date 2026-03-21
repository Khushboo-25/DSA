class Solution {
public:
    int reverse(int x) {
        
        long long ans=0;
        long long t=x;
        int p=0;
        if(t<0)
        {
            p=1;
            t*=-1;
        }
        while(t>0)
        {
            ans=ans*10+t%10;
            t/=10;
        }
        if(p==1)
        ans*=-1;
        if(ans<INT_MIN || ans>INT_MAX)
        return 0;
        return ans;
    }
};