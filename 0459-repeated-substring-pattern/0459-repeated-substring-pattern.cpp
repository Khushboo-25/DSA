class Solution {
public:
    bool check(int i,string &s)
    {
        string st=s.substr(0,i);
        for(int j=i;j<s.size();j+=i)
        {
            if(st!=s.substr(j,i))
                return 0;
            
        }
        return 1;
    }
    bool repeatedSubstringPattern(string s) 
    {
        int n=s.size();
        for(int i=1;i<=n/2;i++)
        {
            if(check(i,s))
                return 1;
            
        }
        return 0;
        
    }
};