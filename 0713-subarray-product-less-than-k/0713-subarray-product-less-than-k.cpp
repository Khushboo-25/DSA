class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if(k <= 1) return 0;  // important edge case

    int n = nums.size();
    long long prod = 1;
    int s = 0;
    int count = 0;

    for(int e = 0; e < n; e++) {
        prod *= nums[e];

        while(prod >= k) {
            prod /= nums[s];
            s++;
        }

        count += (e - s + 1);
    }

    return count;
        
    }
};