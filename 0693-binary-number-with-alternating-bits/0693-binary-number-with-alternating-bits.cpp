class Solution {
public:
    bool hasAlternatingBits(int n) 
    {
        int s=n%2;
        n=n/2;
        while(n)
        {
            if(n%2==s)
            {
                return false;
            }
            else
            {
                s=n%2;
            }
            n=n/2;
        }
        return true;
    }
};