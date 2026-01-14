class Solution {
public:
    int isPrefixOfWord(string st, string sr) {
        
        int m=sr.size();
        int cn=0;
        string c="";
        for(auto it:st)
        {
            if(it==' ')
            {
                if(!c.empty())
                cn++;
                if(c.size()>=m && c.substr(0,m)==sr)
                {
                    return cn;
                }
                c="";
            }
            else
            c+=it;
        }
        if(!c.empty())
        cn++;
        if(c.size()>=m && c.substr(0,m)==sr)
        {
            return cn;
        }
        return -1;
    }
};