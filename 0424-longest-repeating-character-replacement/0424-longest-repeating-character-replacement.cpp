class Solution {
public:
bool check(int sz, string &s,int &k,int &n)
{
    vector<int>fp(26,0);
    for(int i=0;i<sz-1;i++)
    {
        fp[s[i]-'A']++;
    }
    for(int i=sz-1;i<n;i++)
    {
        fp[s[i]-'A']++;
        if(i-sz>=0)
        {
            fp[s[i-sz]-'A']--;
        }
        int rq=sz-*max_element(fp.begin(),fp.end());
        if(rq<=k)
        return 1;
    }
    return 0;
    

}
    int characterReplacement(string st, int k) 
    {
        
        int n=st.size();
        int s=1,e=n;
        int ans=0;
        while(s<=e)
        {
            int m=s+(e-s)/2;
            if(check(m,st,k,n))  ///total -maxf<=k
            {
                ans=m;
                s=m+1;

            }
            else
            e=m-1;
        }
        return ans;
        
    }
};