class Solution {
public:
    string licenseKeyFormatting(string s, int k) 
    {
        // return "";
        reverse(s.begin(),s.end());
        string ans="";
        int k1=0;
        for(auto it:s)
        {
            if(it=='-')
            continue;
            if(it>='a' && it<='z')
            {
                char c='A';
                c+=it-'a';
                ans+=c;
            }
            else
            ans+=it;
            k1++;
            if(k1==k)
            {
                ans+='-';
                k1=0;
            }
        }
        if(ans.size()>=1 &&ans.back()=='-')
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans ;
        
    }
};