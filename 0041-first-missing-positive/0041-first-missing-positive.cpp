class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,bool>pp;
        for(auto it:nums)
        pp[it]=1;
        int n=nums.size();
        int i=1;
        while(i<=n)
        {
            if(pp.find(i)==pp.end())
            return i;
            i++;

        }
        return n+1;
    }
};