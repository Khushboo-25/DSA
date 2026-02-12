class Solution {
public:
    string reverseByType(string s) 
    {
        string sp="";
        string cr="";
        for(auto it:s)
        {
            if(it<='z' && it>='a')
            cr+=it;
            else
            sp+=it;
        }
        reverse(sp.begin(),sp.end());
        reverse(cr.begin(),cr.end());
        int i=0,j=0;
        string ans="";
        for(auto it:s)
        {
            if(it<='z' && it>='a')
            ans+=cr[i++];
            else
            ans+=sp[j++];
        }
        return ans;
        
    }
};