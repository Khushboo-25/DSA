class Solution {
public:
    string countAndSay(int n) 
    {
        string s;
        s="1";
        while(n>1)
        {
            int cn=0;
            char c='*';
            string s2="";
            for(auto it: s)
            {
                if(it!=c)
                {
                    if(c!='*')
                    {
                        s2+=to_string(cn);
                        s2+=c;
                    }
                    cn=1;
                    c=it;
                }
                else
                {
                    cn++;
                }
            }
            s2+=to_string(cn);
            s2+=c;
            n--;
            s=s2;
        }
        return s;
        
    }
};