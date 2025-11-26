class Solution {
public:
void call(int i,int &n,vector<int>&vv,vector<vector<int>>&adj)
{
    vv[i]=1;
    for(auto it: adj[i])
    {
        if(vv[it]==0)
        call(it,n,vv,adj);
    }
}
    int maximumDetonation(vector<vector<int>>& bm) 
    {
        int n=bm.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int x1=bm[i][0],y1=bm[i][1],r1=bm[i][2];
                int x2=bm[j][0],y2=bm[j][1],r2=bm[j][2];
                long long  d=(x1-x2)*1ll*(x1-x2)+(y1-y2)*1ll*(y1-y2);
                long long d1=r1*1ll*r1,d2=r2*1ll*r2;


                if(d<=d1)
                {
                    adj[i].push_back(j);
                }
                if(d<=d2)
                {
                    adj[j].push_back(i);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int>vv(n,0);
            call(i,n,vv,adj);
            int ans1=0;
            for(auto it:vv)
            ans1+=it;
            ans=max(ans,ans1);
        }
        return ans;
        
    }
};