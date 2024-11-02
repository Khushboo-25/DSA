class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& iter, vector<int>& newit) 
    {
        iter.push_back(newit);
        sort(iter.begin(),iter.end());
        int n=iter.size();
        vector<vector<int>>ans;
        ans.push_back(iter[0]);
        for(int i=1;i<n;i++)
        {
            auto it=ans.back();
            if(it[1]>=iter[i][0])
            {
                int f=max(iter[i][1],it[1]);
                int s=it[0];
                ans.pop_back();
                ans.push_back({s,f});
            }
            else
            {
                ans.push_back(iter[i]);
            }
        }
        return ans;
        

    }
};