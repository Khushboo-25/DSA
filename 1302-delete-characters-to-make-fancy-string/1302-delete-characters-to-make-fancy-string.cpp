class Solution {
public:
    string makeFancyString(string s) 
    {
        string ans="";
        ans+=s[0];
        if(s.size()>1)
        ans+=s[1];
        int n=s.size();
        for(int i=2;i<n;i++)
        {
            if(s[i]==ans[ans.size()-1] && s[i]==ans[ans.size()-2])
            continue;
            else
            ans+=s[i];
        }
        return ans;
        
    }
};