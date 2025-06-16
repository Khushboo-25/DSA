class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> lakeLastFull;  // lake -> last day it was full
        set<int> dryDays;                      // indexes where we can dry
        vector<int> ans(n, 1);                 // initially put 1 for dry days
                                               // we'll fix to -1 for rain days
        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dryDays.insert(i);  // this day is available for drying
                continue;
            }

            int lake = rains[i];
            ans[i] = -1;  // rain day

            if (lakeLastFull.find(lake) != lakeLastFull.end()) {
                int lastDay = lakeLastFull[lake];
                auto it = dryDays.upper_bound(lastDay);
                if (it == dryDays.end()) return {};  // no dry day after last rain -> flood
                ans[*it] = lake;   // dry this lake on day *it
                dryDays.erase(it); // mark this dry day as used
            }

            lakeLastFull[lake] = i;
        }

        return ans;
    }
};
