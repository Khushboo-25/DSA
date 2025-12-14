class Solution {
public:
    string reverseWords(string s) 
    {
        int n=s.size();
        vector<pair<string,int>>ans;
        string s1="";
        int cn=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]<='z' && s[i]>='a')
            {
                s1+=s[i];
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                {
                    cn++;
                }
            }
            else if(!s1.empty())
            {
                ans.push_back({s1,cn});
                cn=0;
                s1="";
            }
        }
        if(!s1.empty())
        {
            ans.push_back({s1,cn});
        }
        int n1=ans.size();
        cout<<n1<<" ";
        int cn0=ans[0].second;
        string fs="";
        fs+=ans[0].first;
        for(int i=1;i<n1;i++)
        {
            string s2=ans[i].first;
            if(ans[i].second==cn0)
            {
                
                reverse(s2.begin(),s2.end());
                
            }
            fs+=" "+s2;
        }
        return fs;
        
        
    }
};