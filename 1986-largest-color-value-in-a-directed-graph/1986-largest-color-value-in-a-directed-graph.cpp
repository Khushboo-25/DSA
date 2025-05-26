class Solution {
public:
int dfs(int i,string &colors,vector<vector<int>>&adj,
        vector<vector<int>> &count,vector<int> &vv)
        {
            if(vv[i]==0)
            {
                vv[i]=1;
                for(auto nw:adj[i])
                {
                    if(dfs(nw,colors,adj,count,vv)==INT_MAX)
                    return INT_MAX;
                    for(int c=0;c<26;c++)
                    count[i][c]=max(count[i][c], count[nw][c]);
                }
                ++count[i][colors[i]-'a'];
                vv[i]=2;

            }
            return vv[i] == 2 ? count[i][colors[i] - 'a'] : INT_MAX;
        }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // unordered_map<char,int>pp;
        int n=colors.size();
        vector<vector<int>>adj(n),count(n,vector<int>(26,0));
        vector<int>vv(n,0);
        for(auto it: edges)
        {
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
        }
        int ans=0;
        for(int i=0;i<n && ans!=INT_MAX;i++)
        {
            ans=max(ans,dfs(i,colors,adj,count,vv));
        }
        return ans == INT_MAX ? -1 : ans;

    }
};