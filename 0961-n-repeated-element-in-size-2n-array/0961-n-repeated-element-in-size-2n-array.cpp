class Solution {
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        int n=nums.size()/2;
        unordered_map<int,int>pp;
        for(auto it:nums)
        {
            pp[it]++;
            if(pp[it]>=n)
            return it;
        }
        return -1;
        
    }
};