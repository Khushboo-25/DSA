class Solution {
public:
    long long countSubstrings(string s, char c) 
    {
        int n=s.size();
        vector<int>an(n,0);
        if(s[n-1]==c)
        an[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            an[i]=an[i+1];
            if(s[i]==c)
            an[i]++;
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==c)
            {
                ans+=an[i];
            }
        }
        return ans;

        
    }
};