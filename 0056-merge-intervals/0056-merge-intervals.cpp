class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) 
    {
        sort(it.begin(),it.end());
        int n=it.size();
        vector<vector<int>>ans;
        ans.push_back(it[0]);
        for(int i=1;i<n;i++)
        {
            int s=it[i][0];
            int e=it[i][1];
            while(!ans.empty() && ans.back()[1]>=s)
            {
                s=min(s,ans.back()[0]);
                e=max(e,ans.back()[1]);
                ans.pop_back();
            }
            ans.push_back({s,e});
        }
        return ans;
        
    }
};