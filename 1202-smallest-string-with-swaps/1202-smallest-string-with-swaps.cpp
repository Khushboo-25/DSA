class Solution {
public:
void call(int i,vector<int>&pv,vector<int>&vv,vector<vector<int>>&adj)
{
    pv.push_back(i);
    vv[i]=1;
    for(auto it:adj[i])
    {
        if(vv[it]==0)
        call(it,pv,vv,adj);
    }
}
string smallestStringWithSwaps(string s,vector<vector<int>>&pr)
{
    int n=s.size();
    vector<vector<int>>adj(n);
    for(auto it:pr)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<vector<int>>pp;
    vector<int>vv(n,0);
    for(int i=0;i<n;i++)
    {
        vector<int>pv;
        if(vv[i]==0)
        {
            call(i,pv,vv,adj);
        }
        if(!pv.empty())
        pp.push_back(pv);
    }
    for(auto it:pp)
    {
        string s1="";
        for(auto in:it)
        {
            s1+=s[in];
        }
        sort(s1.begin(),s1.end());
        vector<int>ins=it;
        sort(ins.begin(),ins.end());
        for(int i=0;i<ins.size();i++)
        s[ins[i]]=s1[i];
    }
    return s;
}
};