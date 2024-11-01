class Solution {
public:
bool check(int sz,string s,int &n)
{
    // sz=_g*sz;
    if(n%sz!=0)
    return 0;
    string s1=s.substr(0,sz);
    sort(s1.begin(),s1.end());
    for(int i=sz;i<n;i+=sz)
    {
        // if(i+sz>n)
        // return 0;
        string s2=s.substr(i,sz);
        sort(s2.begin(),s2.end());
        if(s1!=s2)
        return 0;
    }
    return 1;
}
    int minAnagramLength(string s) {
        int n=s.size();
        unordered_map<char,int>fr;
        int _g=0;
        for(auto it: s)
        {
            fr[it-'a']++;
            _g=fr[it-'a'];

        }
        for(auto it:fr)
        {
            _g=__gcd(it.second,_g);
        }
        // cout<<_g;
        int mnl=0;
        for(auto it:fr)
        {
            mnl+=it.second/_g;
        }
        cout<<mnl<<" *";
        // int ans=n/mnl;
        // int len=mnl;
        while(mnl<=n)
        {
            if(check(mnl,s,n))
            return mnl;
            mnl*=2;
        }
        return n;
    }
};