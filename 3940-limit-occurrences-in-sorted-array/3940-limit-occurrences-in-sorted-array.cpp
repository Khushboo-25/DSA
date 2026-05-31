class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) 
    {
        vector<int>ans;
        unordered_map<int,int>pp;
        for(auto it:nums)
        {
            if(pp.find(it)==pp.end()||(pp.find(it)!=pp.end() && pp[it]<k))
            {
                ans.push_back(it);
                pp[it]++;
            }
        }
        return ans;
        
    }
};