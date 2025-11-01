class Solution {
public:
    int longestSubsequence(vector<int>& nums) 
    {
        int ans=0;
        int n=nums.size();
        unordered_map<int,int>pp;
        for(auto it: nums)
        {
            pp[it]++;
            pp[it]%=2;
        }
        if(pp.size()==1 && nums[0]==0)
        return 0;
        int xr=0;
        for(auto it:pp)
        {
            if(it.first>0 && it.second!=0)
            xr^=it.first;
        }
        if(xr==0)
        {
            return n-1;
        }
        return n;
        
    }
};