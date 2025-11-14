class Solution {
public:
    int sumOfUnique(vector<int>& nums) 
    {
        unordered_map<int,int>pp;
        for(auto it: nums)
        {
            pp[it]++;
        }
        int ans=0;
        for(auto it:pp)
        {
            if(it.second==1)
            ans+=it.first;
        }
        return ans;
        
    }
};