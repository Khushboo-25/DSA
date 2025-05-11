class Solution {
public:
bool check(int m,int &x)
{
    
    if( m*m<=x)
    return 1;
    return 0;
}
    int mySqrt(int x) 
    {
        return sqrt(x);
        int s=0,e=x;
        int ans=x;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(check(m,x))
            {
                
                e=m-1;
            }
            else
            {
                ans=m;
                s=m+1;
            }
        }
        return ans;
        
    }
};