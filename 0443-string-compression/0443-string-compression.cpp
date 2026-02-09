class Solution {
public:
    int compress(vector<char>& s) 
    {
        string ans="";
        char ls=s[0];
        int cn=1;
        int n=s.size();
        for(int i=1;i<n;i++)
        {
            if(s[i]==ls)
            {
                cn++;
            }
            else
            {
                ans+=ls;
                if(cn!=1)
                {
                    string s1=to_string(cn);
                    // cout<<s1<<" ";
                    ans+=s1;
                }
                ls=s[i];
                cn=1;
            }
        }
        ans+=ls;
        if(cn!=1)
        {
            string s1=to_string(cn);

            ans+=s1;
        }
        for(int i=0;i<ans.size();i++)
        {
            s[i]=ans[i];
        }
        return ans.size();
        
    }
};