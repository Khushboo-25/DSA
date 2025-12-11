class Solution {
public:

bool cycle(int i, vector<vector<int>>&adj, vector<int>&vis, vector<int>&stk)
{
    vis[i] = 1;
    stk[i] = 1;

    for(int nxt : adj[i])
    {
        if(!vis[nxt])
        {
            if(cycle(nxt, adj, vis, stk)) return true;
        }
        else if(stk[nxt])
        {
            return true;
        }
    }
    stk[i] = 0;
    return false;
}

void topo(int i, vector<vector<int>>&adj, vector<int>&vis, vector<int>&tp)
{
    vis[i] = 1;
    for(int nxt : adj[i])
    {
        if(!vis[nxt]) topo(nxt, adj, vis, tp);
    }
    tp.push_back(i);
}

vector<int> getTopo(int k, vector<vector<int>>&adj)
{
    vector<int>vis(k+1,0), tp;

    for(int i=1;i<=k;i++)
    {
        if(!vis[i]) topo(i, adj, vis, tp);
    }

    reverse(tp.begin(), tp.end());
    return tp;
}

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowC, vector<vector<int>>& colC) 
{
    vector<vector<int>> rowAdj(k+1), colAdj(k+1);

    for(auto &it : rowC)
        rowAdj[it[0]].push_back(it[1]);

    for(auto &it : colC)
        colAdj[it[0]].push_back(it[1]);

    // cycle check
    vector<int>vis1(k+1,0), stk1(k+1,0), vis2(k+1,0), stk2(k+1,0);

    for(int i=1;i<=k;i++)
    {
        if(!vis1[i] && cycle(i, rowAdj, vis1, stk1)) return {};
        if(!vis2[i] && cycle(i, colAdj, vis2, stk2)) return {};
    }

    // topological orders
    vector<int> rowTopo = getTopo(k, rowAdj);
    vector<int> colTopo = getTopo(k, colAdj);

    // positions
    vector<int> rowPos(k+1), colPos(k+1);

    for(int i=0;i<k;i++)
    {
        rowPos[rowTopo[i]] = i;
        colPos[colTopo[i]] = i;
    }

    // build matrix
    vector<vector<int>>ans(k, vector<int>(k, 0));

    for(int v=1; v<=k; v++)
    {
        int r = rowPos[v];
        int c = colPos[v];
        ans[r][c] = v;
    }

    return ans;
}
};
