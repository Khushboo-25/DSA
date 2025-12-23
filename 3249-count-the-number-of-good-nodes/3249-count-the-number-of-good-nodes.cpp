class Solution {
public:
    int call(int i, int parent, vector<vector<int>>& adj, int &cn)
    {
        int ans = 1;
        unordered_map<int,int> pp;

        for(auto it : adj[i])
        {
            if(it == parent) continue;  
            int s1 = call(it, i, adj, cn);
            ans += s1;
            pp[s1]++;
        }

        if(pp.size() <= 1)
            cn++;

        return ans;
    }

    int countGoodNodes(vector<vector<int>>& edges)
    {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);

        for(auto &it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); 
        }

        int cn = 0;
        call(0, -1, adj, cn);
        return cn;
    }
};
