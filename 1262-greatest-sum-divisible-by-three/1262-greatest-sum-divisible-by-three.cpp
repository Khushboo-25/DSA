class Solution {
public:
    int maxSumDivThree(vector<int>& nums) 
    {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> m1, m2;
        for (auto it : nums)
        {
            ans += it;
            if (it % 3 == 1)
            m1.push(it);
            else if (it % 3 == 2)
            m2.push(it);
        }

        if (ans % 3 == 0)
            return ans;
        vector<int> mn1, mn2;
        for (int i = 0; i < 2; i++) {
            if (!m1.empty()) {
                mn1.push_back(m1.top());
                m1.pop();
            }
        }
        for (int i = 0; i < 2; i++) {
            if (!m2.empty()) {
                mn2.push_back(m2.top());
                m2.pop();
            }
        }
        int removeCost = INT_MAX;
        if (ans % 3 == 1)
        {
            if (mn1.size() >= 1) 
                removeCost = min(removeCost, mn1[0]);
            if (mn2.size() >= 2) 
                removeCost = min(removeCost, mn2[0] + mn2[1]);
        }
        else 
        {
            if (mn2.size() >= 1) 
                removeCost = min(removeCost, mn2[0]);
            if (mn1.size() >= 2) 
                removeCost = min(removeCost, mn1[0] + mn1[1]);
        }

        if (removeCost == INT_MAX) 
            return 0;

        return ans - removeCost;
    }
};
