class Solution {
public:
    vector<int> minCosts(vector<int>& cost) 
    {
        int ans=INT_MAX;
        for(auto &it:cost)
        {
            ans=min(ans,it);
            it=ans;
        }
        return cost;
        
    }
};