class Solution {
public:
    int findMinDifference(vector<string>&tt) 
    {
        vector<int>tm;
        for(auto it: tt)
        {
            int hr=(it[0]-'0')*10+(it[1]-'0');
            int mn=(it[3]-'0')*10+(it[4]-'0');
            tm.push_back(hr*60+mn);
        }
        int n=tm.size();
        int ans=INT_MAX;
        sort(tm.begin(),tm.end());
        for(int i=1;i<n;i++)
        {
            ans=min(ans,tm[i]-tm[i-1]);
        }
        ans=min(ans,60*24-1-tm.back()+tm[0]+1);
        return ans;
    }
};