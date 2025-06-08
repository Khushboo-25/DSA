class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> st;
        vector<int> ans;
        for (int i = nums.size() - 1; i >= 0; --i) {
            auto it = lower_bound(st.begin(), st.end(), nums[i]);
            ans.push_back(it - st.begin());
            st.insert(it, nums[i]); // insert at correct position in log n time
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
