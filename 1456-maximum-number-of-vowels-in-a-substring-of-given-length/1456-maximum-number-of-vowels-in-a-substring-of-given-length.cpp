class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int n=s.size();
        vector<int>av(n,0);
        for(int i=0;i<n;i++)
        {
            if(i-1>=0)
            av[i]+=av[i-1];
            if(s[i]=='a' || s[i]=='e'|| s[i]=='i'|| s[i]=='o' ||s[i]=='u')
            {
                av[i]++;
            }
        }
        int ans=av[k-1];
        for(int i=k;i<n;i++)
        {
            int nv=av[i]-av[i-k];
           
            ans=max(ans,nv);
        }
        return ans;

        
    }
};