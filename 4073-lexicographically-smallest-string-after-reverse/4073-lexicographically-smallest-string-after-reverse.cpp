class Solution {
public:
    string lexSmallest(string s) 
    {
        string lf="";
        string rf=s;
        string ans=s;
        int n=s.size();
        for(int i=1;i<=n;i++)
        {
            lf=s[i-1]+lf;
            rf=rf.substr(1);
            string ans1=lf+rf;
            ans=min(ans,ans1);
        }
        lf=s;
        rf="";
        for(int i=n-1;i>=0;i--)
        {
            rf=rf+s[i];
            lf=lf.substr(0,i);
            string ans1=lf+rf;
            ans=min(ans,ans1);
        }
        return ans;
        
    }
};