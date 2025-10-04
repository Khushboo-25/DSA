class Solution {
public:
string add(string s)
{

    int cr=1;
    string ans="";
    int n=s.size();
    for(int i=n-1;i>=0;i--)
    {
        if(cr==0)
        {
            ans+=s[i];
        }
        else // 1
        {
            if(s[i]=='0')
            {
                ans+='1';
                cr=0;
            }
            else
            {
                ans+='0';
                cr=1;
            }
        }
    }
    if(cr==1)
    ans+='1';
    reverse(ans.begin(),ans.end());
    return ans;
}
int call(string s,unordered_map<string,int>&pp)
{
    if(s.size()<=1)
    return 0;
    if(s.size()>=1000)
    return 1e9;
    
    if(pp.find(s)!=pp.end())
    return pp[s];
    int n=s.size();
    int ans=INT_MAX;
    if(s[n-1]=='0')
    {
        string s1=s.substr(0,n-1);
        ans=min(ans,1+call(s1,pp));
    }
    else
    {
        string s2=add(s);
        ans=min(ans,1+call(s2,pp));
    }
    return pp[s]=ans;
}
    int numSteps(string s) 
    {
        unordered_map<string,int>pp;
        return call(s,pp);

        
    }
};