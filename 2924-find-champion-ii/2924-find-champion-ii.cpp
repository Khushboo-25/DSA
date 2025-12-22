class Solution {
public:

    int findChampion(int n, vector<vector<int>>& edges) 
    {
        vector<int>in(n,0);
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            in[it[1]]++;
        }
        
        vector<int>ans;
        for(int i=n-1;i>=0;i--)
        {
            if(in[i]==0)
            {
                ans.push_back(i);
            }
        }
        if(ans.size()!=1)
        return -1;
        return ans[0];
        
    }
};