class Solution {
public:
void call(string s1,int i,int &n,string &s,vector<string>&ans)
{
    if(i>=n)
    {
        ans.push_back(s1);
        return ;
    }
    if(s[i]<='9' && s[i]>='0')
    {
        s1+=s[i];
        call(s1,i+1,n,s,ans);
    }
    else if(s[i]<='z'&& s[i]>='a')
    {
        s1+=s[i];
        call(s1,i+1,n,s,ans);
        s1.pop_back();
        char c='A';
        c+=s[i]-'a';
        s1+=c;
        call(s1,i+1,n,s,ans);
    }
    else if(s[i]<='Z'&& s[i]>='A')
    {
        s1+=s[i];
        call(s1,i+1,n,s,ans);
        s1.pop_back();
        char c='a';
        c+=s[i]-'A';
        s1+=c;
        call(s1,i+1,n,s,ans);
    }
}
    vector<string> letterCasePermutation(string s) 
    {
        int n=s.size();
        vector<string>ans;
        call("",0,n,s,ans);
        return ans;
        
    }
};