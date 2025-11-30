class Solution {
public:
    int largestAltitude(vector<int> &gain)
    {
        int ans=0;
        int pv=0;
        for(auto it:gain)
        {
            pv+=it;
            ans=max(ans,pv);
        }
        return ans;
        
    }
};