class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) 
    {
        int ans=0;
        unordered_map<int,int>pp;
        for(auto it: nums)
        pp[it]++;
        for(auto it: pp)
        {
            if(it.second%k==0)
            ans+=it.first*it.second;
        }
        return ans;
        
    }
};