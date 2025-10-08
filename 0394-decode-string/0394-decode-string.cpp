class Solution {
public:
string solve(string &s,int &i)
{
    int n=s.size();
    int num=0;
    string fs="";
    while(i<n)
    {
        if(isdigit(s[i]))
        {
            num=num*10+(s[i]-'0');
            i++;
        }
        else if(s[i]=='[')
        {
            i++;
            string ans1=solve(s,i);
            for(int j=0;j<num;j++)
            {
                fs+=ans1;
            }
            num=0;
        }
        else if(s[i]==']')
        {
            i++;
            return fs;
        }
        else
        {
            fs+=s[i];
            i++;
        }
    }
    return fs;

}
    string decodeString(string s) 
    {
        int i=0;
        return solve(s,i);
        
    }
};