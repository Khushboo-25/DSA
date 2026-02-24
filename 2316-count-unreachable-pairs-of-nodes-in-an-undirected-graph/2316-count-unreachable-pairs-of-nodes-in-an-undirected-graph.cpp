class Solution {
public:
int find(int i,vector<int>&pr)
{
    if(pr[i]==i)
    return i;
    return pr[i]=find(pr[i],pr);
}
void merge(int u,int v,vector<int>&pr)
{
    int fu=find(u,pr);
    int fv=find(v,pr);
    if(fu<=fv)
    {
        pr[fv]=fu;
    }
    else
    {
        pr[fu]=fv;
    }
    
}
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<int>pr(n,-1);
        for(int i=0;i<n;i++)
        pr[i]=i;
        for(auto it:edges)
        {
            merge(it[0],it[1],pr);
        }
        unordered_map<int,int>pp;
        for(auto it:pr)
        {
            pp[find(it,pr)]++;
        }
        vector<int>ps;
        for(auto it:pp)
        {
            ps.push_back(it.second);
            // cout<<it.second<<" ";
        }
        long long ans = 0, sum = 0;

        for(auto &it : pp)
        {
            ans += 1LL * sum * it.second;
            sum += it.second;
        }

        return ans;

        
        
    }
};