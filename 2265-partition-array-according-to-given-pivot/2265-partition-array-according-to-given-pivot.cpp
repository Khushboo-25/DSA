class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int pv) 
    {
        int n=a.size();
        vector<int>vv(n,INT_MIN);
        int s=0,e=n-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]<pv)
            {
                vv[s++]=a[i];
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>pv)
            {
                vv[e--]=a[i];
            }
        }
        for(auto &t:vv)
        {
            if(t==INT_MIN)
            {
                t=pv;
            }
        }
        return vv;
        
    }
};