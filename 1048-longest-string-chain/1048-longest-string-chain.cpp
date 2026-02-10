class Solution {
public:
bool f(string s1,string s2)
{
    int n=s2.size();
    for(int i=0;i<n;i++)
    {
        string ts=s2.substr(0,i)+s2.substr(i+1);
        if(ts==s1)
        return 1;
    }
    return 0;
}
int call(vector<int>&dp,int i,vector<vector<int>>&adj)
{

    if(adj[i].empty())
    return 1;
    if(dp[i]!=-1)
    return dp[i];
    int ans=1;
    for(auto it:adj[i])
    {
        ans=max(ans,1+call(dp,it,adj));
    }
    return dp[i]=ans;

}
    int longestStrChain(vector<string>& words) 
    {
        int n=words.size();
        vector<vector<int>>adj(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j && words[i].size()==words[j].size()-1 && f(words[i],words[j]))
                {
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++)
        {
            ans=max(ans,call(dp,i,adj));
        }
        return ans;
        
    }
};