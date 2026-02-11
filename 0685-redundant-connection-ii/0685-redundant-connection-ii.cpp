class Solution {
public:
    int findpr(int x, vector<int>& pr)
    {
        if(pr[x] == x) return x;
        return pr[x] = findpr(pr[x], pr);
    }

    bool check(int skip, vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int> pr(n+1);
        vector<int> indegree(n+1, 0);

        for(int i=1;i<=n;i++)
            pr[i] = i;

        for(int i=0;i<n;i++)
        {
            if(i == skip) continue;

            int u = edges[i][0];
            int v = edges[i][1];

            indegree[v]++;
            if(indegree[v] > 1)
                return false;

            int pu = findpr(u, pr);
            int pv = findpr(v, pr);

            if(pu == pv)
                return false;

            pr[pv] = pu;
        }

        // Check exactly one root
        int rootCount = 0;
        for(int i=1;i<=n;i++)
            if(indegree[i] == 0)
                rootCount++;

        if(rootCount != 1)
            return false;

        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
        for(int i = edges.size()-1; i >= 0; i--)
        {
            if(check(i, edges))
                return edges[i];
        }

        return {};
    }
};
