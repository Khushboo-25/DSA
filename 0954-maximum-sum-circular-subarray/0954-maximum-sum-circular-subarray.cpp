class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        int s1 = 0, s2 = 0;
        int ans = nums[0], ans2 = nums[0];

        for (int j = 0; j < n; j++) {
            sum += nums[j];

            s2 = max(nums[j], s2 + nums[j]);
            ans2 = max(ans2, s2);

            s1 = min(nums[j], s1 + nums[j]);
            ans = min(ans, s1);
        }

        if (ans2 < 0)  // all numbers are negative
            return ans2;

        return max(ans2, sum - ans); 
    }
};
