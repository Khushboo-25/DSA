class Solution {
public:
int mod=1e9+7;
    int numSub(string s) 
    {
        vector<int>a(1e5+1,0);
        for(int i=1;i<=1e5;i++)
        {
            a[i]=(a[i-1]+i)%mod;
        }
        int c=0;
        int ans=0;
        for(auto it:s)
        {
            if(it=='1')
            {
                c++;
            }
            else
            {
                ans+=a[c];
                c=0;
            }
        }
        ans+=a[c];
        return ans;
    }
};