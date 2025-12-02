class Solution {
public:
int reductionOperations(vector<int>&nums)
{
    sort(nums.begin(), nums.end());
    
    int n = nums.size();
    int ops = 0;
    
    // For every distinct value except the smallest
    for(int i = 1; i < n; i++)
    {
        if(nums[i] != nums[i-1])
            ops += (n - i);
    }
    return ops;
}
};
