class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& rd) 
    {
        vector<int>d(n,0);
        for(auto it: rd)
        {
            int x=it[0];
            int y=it[1];
            d[x]++;
            d[y]++;
        }
        vector<pair<int,int>>pr;
        for(int i=0;i<n;i++)
        {
            pr.push_back({d[i],i});
        }
        sort(pr.begin(),pr.end());
        int cn=1;
        unordered_map<int,int>pp;
        for(auto it: pr)
        {
            pp[it.second]=cn;
            cn++;
        }
        long long ans=0;
        for(auto it:rd)
        {
            int x=it[0];
            int y=it[1];
            ans+=pp[x]+pp[y];
        }
        return ans;
        
    }
};