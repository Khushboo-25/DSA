class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            arr[i]=arr[i-1]^arr[i];
        }
        vector<int> ans;
        for(auto it:queries)
        {
            int lf=it[0];
            int rf=it[1];
            int ans1=0;
            ans1^=arr[rf];
            if(lf-1>=0)
            {
                ans1^=arr[lf-1];
            }
            ans.push_back(ans1);
        }
        return ans;

    }
};