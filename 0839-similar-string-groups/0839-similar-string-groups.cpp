class Solution {
public:
void dfs(int i,vector<vector<int>>&adj,vector<int>&vv)
{
    vv[i]=1;
    for(auto it: adj[i])
    {
        if(vv[it]==0)
        dfs(it,adj,vv);
    }
}
bool call(string &s1,string &s2,int &m)
{
    vector<int>df;
    for(int i=0;i<m;i++)
    {
        if(s1[i]!=s2[i])
        df.push_back(i);
        if(df.size()>2)
        return 0;
    }
    if(df.empty())
    return 1;
    if(df.size()==1)
    return 0;
    if(s2[df[0]]==s1[df[1]] && s1[df[0]]==s2[df[1]])
    return 1;
    return 0;
}
    int numSimilarGroups(vector<string>& strs) 
    {
        int n=strs.size();
        int m=strs[0].size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(call(strs[i],strs[j],m))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vv(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(vv[i]==0)
            {
                ans++;
                dfs(i,adj,vv);
            }
        }
        return ans;
    }
};