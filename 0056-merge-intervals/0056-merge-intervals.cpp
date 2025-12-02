class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& iter) 
    {
        int n=iter.size();
        sort(iter.begin(),iter.end());
        vector<vector<int> > ans;
        ans.push_back(iter[0]);
        int k=0;
        for(int i=1;i<n;i++)
        {
            if(iter[i][0]<=ans[k][1])
            {
                int s=ans[k][0];
                int e=max(ans[k][1],iter[i][1]);
                ans.pop_back();
                ans.push_back({s,e});
            }
            else
            {
                ans.push_back(iter[i]);
                k++;
            }
        }
        return ans;
        
    }
};