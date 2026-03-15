class Solution {
public:
    int countCommas(int K) 
    {
        int ans=0;
        for(int i=1;i<=K;i++)
        {
            int n=i;
            int cn=0;
            while(n>0)
            {
                cn++;
                n=n/10;
            }
            ans+=max(0,(cn+2)/3-1);
        }
        return ans;
        
    }
};