class Solution {
public:
int mod=1e9+7;
    int valueAfterKSeconds(int n, int k) 
    {
        vector<int>a(n,1);
        vector<int>pv(n,1);
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<n;j++)
            {
                a[j]=(pv[j]%mod+a[j-1]%mod)%mod;
            }
            pv=a;
        }
        return a[n-1];
        
    }
};