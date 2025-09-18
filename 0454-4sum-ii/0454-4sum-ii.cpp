class Solution {
public:
    int fourSumCount(vector<int>& a1, vector<int>& a2, vector<int>& a3, vector<int>& a4) 
    {
        unordered_map<int,int>p1;
        unordered_map<int,int>p2;
        for(auto it:a1)
        {
            for(auto it1:a2)
            p1[it+it1]++;
        }
        for(auto it:a3)
        {
            for(auto it1:a4)
            p2[it+it1]++;
        }
        int ans=0;
        for(auto it: p1)
        {
            ans+=p2[-1*it.first]*it.second;
        }
        return ans;

    }
};
