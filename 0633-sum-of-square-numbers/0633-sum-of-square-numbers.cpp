class Solution {
public:
    bool judgeSquareSum(int c) 
    {
        int s=0,e=(int)sqrt(c);
        while(s<=e)
        {
            long long m=s*1ll*s+e*1ll*e;
            if(m==c)
            {
                return true;
            }
            else if(m<c)
            {
                s++;
            }
            else
            e--;
            
        }
        

        
        return false;
        
    }
};