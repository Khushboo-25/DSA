class Solution {
public:
    int rangeBitwiseAnd(int n, int m) 
    {
        while(n<m)
        {
            m=m&(m-1);
        }
        return n&m;

        
    }
};