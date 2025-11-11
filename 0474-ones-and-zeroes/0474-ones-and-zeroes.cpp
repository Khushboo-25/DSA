class Solution {
public:
int call(int i,int m0,int m1,int &n,int &n0,int &n1,vector<pair<int,int>>&st,unordered_map<string,int>&pp)
{
    if(i>=n)
    return 0;
    int ans=0;
    string fs=to_string(i)+","+to_string(m0)+","+to_string(m1);
    if(pp.find(fs)!=pp.end())
    return pp[fs];
    ans=max(ans,call(i+1,m0,m1,n,n0,n1,st,pp));
    if((m0+st[i].first)<=n0 && (m1+st[i].second)<=n1)
    {
        ans=max(ans,1+call(i+1,m0+st[i].first,m1+st[i].second,n,n0,n1,st,pp));
    }
    return pp[fs]=ans;
}
    int findMaxForm(vector<string>& str, int &n0, int &n1) 
    {
        int n=str.size();
        vector<pair<int,int>>st;
        for(auto it: str)
        {
            int m0=0;
            int m1=0;
            for(auto it1:it)
            {
                if(it1=='0')
                m0++;
                else
                m1++;
            }
            st.push_back({m0,m1});
        }
        unordered_map<string,int>pp;
        return call(0,0,0,n,n0,n1,st,pp);
    }
};