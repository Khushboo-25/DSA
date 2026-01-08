class Solution {
public:
    long long call(long long cn)
    {
        return (cn * (cn + 1)) / 2;
    }

    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long s0 = 0;

        for (auto it : nums)
        {
            if (it == 0)
                s0++;
            else
            {
                ans += call(s0);
                s0 = 0;
            }
        }

        ans += call(s0);
        return ans;
    }
};
