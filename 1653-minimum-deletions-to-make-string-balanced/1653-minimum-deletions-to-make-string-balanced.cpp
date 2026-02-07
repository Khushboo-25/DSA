class Solution {
public:
    int minimumDeletions(string s) 
    {
        int n=s.size();
        vector<int>nb(n,0),na(n,0);
        int bs=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='b')
            {
                bs++;
            }
            nb[i]=bs;
        }
        int as=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='a')
            {
                as++;
            }
            na[i]=as;
        }
        int ans=INT_MAX;
        ans=min(n-na[0],n-nb[n-1]);
        for(int i=1;i<n;i++)
        {
            ans=min(ans,nb[i-1]+na[i]);
        }
        return ans;

    }
};