class Solution {
public:
pair<bool,int> update(string &s,int &n)
{
    bool e1=0;
    int in=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='@')
        {
            e1=1;
            in=i;
        }
        if(s[i]>='A'&& s[i]<='Z')
        {
            char c='a';
            c+=s[i]-'A';
            s[i]=c;
        }
    }
    return {e1,in};
}
    string maskPII(string s) 
    {
        int n=s.size();
        pair<bool,int>nw=update(s,n);
        string ans="";
        if(nw.first)// email
        {
            
            ans+=s[0];
            ans+="*****";
            ans+=s.substr(nw.second-1);
            return ans;
        }
        int k=0;
        bool plus=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                if(k<4)
                {
                    ans+=s[i];
                }
                else
                ans+='*';
                k++;
            }
            if(s[i]=='+')
            plus=1;
        }
        int n1=ans.size();
        int j=0;
        string ans1="";
        int k1=1;
        while(j<n1)
        {
            if(j>=4)
            {
                ans1+='*';
            }
            else
            ans1+=ans[j];
            if(k1!=n1 && (k1==4 || k1==7 || k1==10))
            {
                ans1+='-';
            }
            j++;

            k1++;
        }
        if(ans.size()>10)
        ans1+='+';
        reverse(ans1.begin(),ans1.end());
        
        return ans1;

    }
};