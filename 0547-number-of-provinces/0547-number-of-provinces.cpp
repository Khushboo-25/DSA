class Solution {
public:
int findpr(int x,vector<int>&pr)
{
    if(pr[x]==x)
    return x;
    pr[x]=findpr(pr[x],pr);
    return pr[x];
}
void update(int x,int y,vector<int>&pr)
{
    int px=findpr(x,pr);
    int py=findpr(y,pr);
    if(px<py)
    pr[py]=px;
    else
    pr[px]=py;
}
    int findCircleNum(vector<vector<int>>& edges)
    {
        int n=edges.size();
        vector<int>pr(n,0);
        for(int i=0;i<n;i++)
        pr[i]=i;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(edges[i][j]==1)
                {
                    update(i,j,pr);
                }
            }
        }
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            pr[i]=findpr(i,pr);
            st.insert(pr[i]);
        }
        return st.size();
        
    }
};