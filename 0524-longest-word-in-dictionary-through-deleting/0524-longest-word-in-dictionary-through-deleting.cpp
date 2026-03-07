class Solution {
public:
static bool cmp(const string &a,const string &b)
{
    if(a.size()==b.size())
        return a<b;
    return a.size()>b.size();
}
bool call(string &s1,string &b)
{
    int n=s1.size(),m=b.size();
    int i=0,j=0;
    while(j<m)
    {
        if(s1[i]==b[j])
        {
            i++;
        }
        j++;
    }
    if(i<n)
    return 0;
    return 1;
}
    string findLongestWord(string s,vector<string>&dt) {
        sort(dt.begin(),dt.end(),cmp);
        for(auto it:dt)
        cout<<it<<" ";
        for(auto it:dt)
        {
            if(call(it,s))
            return it;
        }
        return "";
    }
};