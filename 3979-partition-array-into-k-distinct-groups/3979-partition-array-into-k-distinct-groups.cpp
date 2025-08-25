class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) 
    {
        unordered_map<int,int>pp;
        for(auto it: nums)
        {
            pp[it]++;
            
        }
        int n=nums.size();
        for(auto it: pp)
        {
            if(it.second>(n/k))
            return 0;
        }
        if(n%k==0)
        return 1;
        return 0;
        
        
        
    }
};