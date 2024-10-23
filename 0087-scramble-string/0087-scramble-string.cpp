class Solution {
public:
bool isana(string s1,string s2)
{
    vector<int>ff(26,0);
    vector<int>ff2(26,0);
    for(auto it:s1)
    {
        ff[it-'a']++;
    }
    for(auto it:s2)
    {
        ff2[it-'a']++;
    }
    for(int i=0;i<26;i++)
    if(ff[i]!=ff2[i])
    return 0;
    return 1;
}
map<pair<string,string>,bool>pp;
    bool isScramble(string s1, string s2) 
    {
        if(pp.find({s1,s2})!=pp.end())
        return pp[{s1,s2}];
        if(s1.size()!=s2.size())
        return 0;
        if(!isana(s1,s2))
        {
            return 0;
        }
        if(s1.size()==1)
        return 1;
        
        
        int n=s1.size();
        for(int i=1;i<n;i++)
        {
            bool lf1=isScramble(s1.substr(0,i),s2.substr(n-i,i));
            bool rf1=isScramble(s1.substr(i,n-i),s2.substr(0,n-i));
            if(lf1 && rf1)
            return pp[{s1,s2}]=1;
             bool lf=isScramble(s1.substr(0,i),s2.substr(0,i));
            bool rf=isScramble(s1.substr(i,n-i),s2.substr(i,n-i));
            if(lf && rf)
            return pp[{s1,s2}]=1;
        }
        // int i=n-1;
        // int m=0;
        // while(i>0)
        // {
        //     if(isana(s1.substr(0,i),s2.substr(n-i,i)))
        //     {
        //      m=1;
        //      break;
        //     }
        //     else if(isana(s1.substr(0,i),s2.substr(0,i))) ///length i
        //     {
        //         m=2;
        //         break;
        //     }
        //     i--;
        // }
        // // if(i==0)
        // // {
        // //     return 0;
        // // }
        // if(m==1)
        // {
        //     bool lf=isScramble(s1.substr(0,i),s2.substr(n-i,i));
        //     bool rf=isScramble(s1.substr(i,n-i),s2.substr(0,n-i));
        //     if(lf && rf)
        //     return 1;
        //     return 0;
        // }
        // else if(m==2)
        // {
        //     bool lf=isScramble(s1.substr(0,i),s2.substr(0,i));
        //     bool rf=isScramble(s1.substr(i,n-i),s2.substr(i,n-i));
        //     if(lf && rf)
        //     return 1;
        //     return 0;
        // }
        return pp[{s1,s2}]=0;
    }
};