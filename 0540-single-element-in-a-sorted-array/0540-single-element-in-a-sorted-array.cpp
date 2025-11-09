class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int xr=0;
        for(auto it: nums)
        xr^=it;
        return xr;

        
    }
};