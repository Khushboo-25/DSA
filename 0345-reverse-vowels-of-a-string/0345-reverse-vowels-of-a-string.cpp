class Solution {
public:

    string reverseVowels(string s) {
        unordered_map<char,bool>pp;
        pp['a']=1,pp['e']=1,pp['i']=1,pp['o']=1,pp['u']=1;
        pp['A']=1,pp['E']=1,pp['I']=1,pp['O']=1,pp['U']=1;
        string s1="";
        for(auto it:s)
        {
            if(pp.find(it)!=pp.end())
            s1+=it;
        }
        reverse(s1.begin(),s1.end());
        int i=0;
        for(auto &it:s)
        {
            if(pp.find(it)!=pp.end())
            {
                it=s1[i++];
            }
        }
        return s;
    }
};