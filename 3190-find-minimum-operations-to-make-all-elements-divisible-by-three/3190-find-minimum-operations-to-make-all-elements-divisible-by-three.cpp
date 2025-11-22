class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int c=0;
        for(auto it: nums)
        {
            if(it%3!=0)
            {
                c++;
            }
        }
        return c;
        
    }
};