class Solution {
public:
    int gcdOfOddEvenSums(int n) 
    {
        int so=0,se=0;
        for(int i=1;i<=n;i++)
        {
            so+=2*i-1;
            se+=2*i;
        }
        return __gcd(so,se);
        
    }
};