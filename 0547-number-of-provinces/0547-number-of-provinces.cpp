class Solution {
public:
void call(vector<int>&vv,vector<vector<int>>&gp,int i)
{
    vv[i]=1;
    for(auto it: gp[i])
    {
        if(vv[it]==0)
        call(vv,gp,it);
    }
}
    int findCircleNum(vector<vector<int>>&conn) 
    {
        int n=conn.size();
        vector<vector<int>>gp(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j&& conn[i][j]==1)
                {
                    gp[i].push_back(j);
                    gp[j].push_back(i);
                }
            }
        }
        int ans=0;
        vector<int> vv(n,0);
        for(int i=0;i<n;i++)
        {
            if(vv[i]==0)
            {
                ans++;
                call(vv,gp,i);
            }
        }
        return ans;
        
    }
};