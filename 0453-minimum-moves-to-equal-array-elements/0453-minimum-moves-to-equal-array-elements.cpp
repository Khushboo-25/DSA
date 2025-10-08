class Solution 
{
public:
    int minMoves(vector<int>& nums) 
    {
        long long sum = 0;
        for (auto it : nums)
            sum += it;
            
        int mn = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        
        return sum - 1LL * n * mn;
    }
};
