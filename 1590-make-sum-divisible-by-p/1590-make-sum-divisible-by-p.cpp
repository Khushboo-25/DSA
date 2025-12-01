class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        long long total = 0;
        for (int x : nums) total = (total + x) % p;

        if (total == 0) return 0;

        int need = total;  // we need subarray sum % p = need
        unordered_map<int, int> mp; 
        mp[0] = -1;  

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) 
        {
            prefix = (prefix + nums[i]) % p;

            int target = (prefix - need + p) % p;

            if (mp.find(target)!=mp.end()) 
            {
                ans = min(ans, i - mp[target]);
            }

            mp[prefix] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};
