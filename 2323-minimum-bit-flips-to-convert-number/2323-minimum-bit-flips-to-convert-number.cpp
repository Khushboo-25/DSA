class Solution {
public:
    int minBitFlips(int st, int gl) 
    {
        int xr=st^gl;
        int ans=0;
        while(xr)
        {
            ans+=xr%2;
            xr/=2;
        }
        
        return ans;
    }
};