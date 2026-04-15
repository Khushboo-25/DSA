class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) 
    {
        vector<int>dg(10,0);
        for(auto it:nums)
        {
            while(it>0)
            {
                dg[it%10]++;
                it/=10;
            }
        }
        return dg[digit];
        
    }
};