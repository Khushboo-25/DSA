class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
    int s = 0;
    long long sum = 0;
    int ans = INT_MAX;

    for(int e = 0; e < n; e++) {
        sum += nums[e];

        while(sum >= target) {
            ans = min(ans, e - s + 1);
            sum -= nums[s];
            s++;
        }
    }

    return (ans == INT_MAX) ? 0 : ans;
    }
};