class Solution {
public:
    long long countDistinct(long long n) 
    {
        vector<long long> a(16,0);
        a[0]=1;
        // a[1]=1;
        for(int i=1;i<16;i++)
        {
            a[i]=a[i-1]*1ll*9;
        }
        long long ans=0;
        // int c=0;
        string s=to_string(n);
        int m=s.size();
        for(int i=1;i<m;i++)
        {
            ans+=a[i];
        }
        // int in=0;
        for(int i=0;i<m;i++)
        {
            if(s[i]=='0')
            return ans;
            ans+=(s[i]-'0'-1)*1ll*a[m-i-1];
        }
        return ans+1;
        
    }
};