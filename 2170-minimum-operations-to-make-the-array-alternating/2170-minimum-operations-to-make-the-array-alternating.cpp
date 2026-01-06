class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1) return 0;
        map<int,int> p0, p1;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) p0[nums[i]]++;
            else p1[nums[i]]++;
        }
        vector<pair<int,int>> f0, f1;
        for (auto &it : p0) f0.push_back({it.second, it.first});
        for (auto &it : p1) f1.push_back({it.second, it.first});
        sort(f0.rbegin(), f0.rend());
        sort(f1.rbegin(), f1.rend());
        int evenCnt = (n + 1) / 2;
        int oddCnt  = n / 2;
        if (f0[0].second != f1[0].second) 
        {
            return (evenCnt - f0[0].first) + (oddCnt - f1[0].first);
        }

        int ans = INT_MAX;
        if (f0.size() > 1) 
        {
            ans = min(ans,(evenCnt - f0[1].first) + (oddCnt - f1[0].first));
        }
        if (f1.size() > 1) 
        {
            ans = min(ans,(evenCnt - f0[0].first) + (oddCnt - f1[1].first));
        }
        ans = min(ans,(evenCnt - f0[0].first) + (oddCnt));
        ans = min(ans,(evenCnt) + (oddCnt - f1[0].first));
        return ans;
    }
};
