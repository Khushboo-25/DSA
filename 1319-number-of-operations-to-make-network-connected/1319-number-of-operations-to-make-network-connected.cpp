class Solution {
public:
int findpr(int x,vector<int>&pr)
{
    if(pr[x]==x)
    return x;
    return pr[x]=findpr(pr[x],pr);
}
void unpdate(int x,int y,vector<int>&pr)
{
    int px=findpr(x,pr);
    int py=findpr(y,pr);
    if(px<py)
    pr[py]=px;
    else
    pr[px]=py;
}
    int makeConnected(int n, vector<vector<int>>&edges) {
    vector<int>pr(n,0);
    if(edges.size() < n-1)
    return -1;

    for(int i=0;i<n;i++)
    {
        pr[i]=i;
    }
    for(auto it:edges)
    {
        int x=it[0];
        int y=it[1];
        unpdate(x,y,pr);
    }
    unordered_set<int>st;
    for(auto it:pr)
    st.insert(findpr(it,pr));
    
    return st.size()-1;   
    }
};