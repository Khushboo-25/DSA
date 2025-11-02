class Solution {
public:
    int titleToNumber(string s) 
    {
        int ans=0;
        long long p=1;
        int n=s.size();
        for(int i=n-1;i>=0;i--)
        {
            int m=s[i]-'A'+1;
            ans+=p*m;
            p*=26;
        }
        return ans;
        
    }
};