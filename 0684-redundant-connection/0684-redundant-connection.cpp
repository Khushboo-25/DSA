class Solution {
public:
int findpr(int x,vector<int>&pr)
{
    if(pr[x]==x)
    return x;
    return findpr(pr[x],pr);
}
void update(int x,int y,vector<int>&pr)
{
    int px=findpr(x,pr);
    int py=findpr(y,pr);
    if(px<py)
    {
        pr[py]=px;
    }
    else
    {
        pr[px]=py;
    }
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        vector<int>pr(n+1,0);
        for(int i=1;i<=n;i++)
        {
            pr[i]=i;
        }
        for(auto it:edges)
        {
            int x=it[0];
            int y=it[1];
            if(findpr(x,pr)==findpr(y,pr))
            return {x,y};
            update(x,y,pr);
        }
        return {-1,-1};

    }
};