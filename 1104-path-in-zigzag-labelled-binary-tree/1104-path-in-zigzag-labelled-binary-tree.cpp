class Solution {
public:
void call(int i,vector<vector<int>>&adj,vector<int>&ans)
{
    for(auto it:adj[i])
    {
        call(it,adj,ans);
    }
    ans.push_back(i+1);
}
    vector<int> pathInZigZagTree(int label) 
    {
        vector<vector<int>>adj(label+1);
        queue<int>pq;
        vector<int>lv;
        bool dr=1;// right;
        lv.push_back(0);
        int add=1;
        while(add<label)
        {
            
            vector<int>nw;
            int n1=lv.size();
            if(dr)
            {
                for(int i=n1-1;i>=0;i--)
                {
                    if(add<label)
                    {
                    adj[add].push_back(lv[i]);
                    nw.push_back(add);
                    add++;
                    }
                    if(add<label)
                    {
                    adj[add].push_back(lv[i]);
                    nw.push_back(add);
                    add++;
                    }
                }
            }
            else
            {
                for(int i=0;i<n1;i++)
                {
                    if(add<label)
                    {
                    adj[add].push_back(lv[i]);
                    nw.push_back(add);
                    add++;
                    }
                    if(add<label)
                    {
                    adj[add].push_back(lv[i]);
                    nw.push_back(add);
                    add++;
                    }
                }
            }
            lv=nw;
        }
        vector<int>ans;
        call(label-1,adj,ans);
        // reverse(ans.begin(),ans.end());
        return ans;
    }
};