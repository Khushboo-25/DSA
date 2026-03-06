class Solution {
public:
    int minCost(int n) 
    {
        vector<int>vv(n+1,INT_MAX);
        vv[1]=0;

        for(int i=2;i<=n;i++)
        {
            int mn1=i/2;
            int mn2=i-mn1;
            vv[i]=min(vv[mn1]+vv[mn2]+(mn1*mn2),vv[i]);
        }
        return vv[n];
        
    }
};